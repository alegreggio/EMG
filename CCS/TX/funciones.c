/*
 * funciones.c
 *
 *  Created on: 22/8/2016
 *      Author: Alejandro
 */

#include "funciones.h"
#include "variables.h"


uint8_t i	= 0;


void conf_WDT(void)
{
	WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
}

void conf_CLK(void)
{
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL 	= CALDCO_1MHZ;
	BCSCTL2 = DIVS_0; // SMCLK = DCO = 1MHz
}

void conf_IO(void)
{
	P1SEL  	&= 	~(BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7); //con un 0 en el bit configuro el pin como GPIO
	P1DIR	|=  BIT1 + BIT2 + BIT4 + BIT5 + BIT6; //los demas como entrada (0)
	P1IE 	|= 	BIT3;                    // P1.3 interrupt enabled
	P1IES 	|= 	BIT3;                    // P1.3 interrupt activa por flanco descendente
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	P1OUT	&=	~BIT1;						// nRF24L01+ desactivado
	P1OUT	&=	~BIT4;
	P1SEL	|=	BIT0;
}

void conf_USI(void)
{
	USICTL0		= USIPE5 + USIMST + USIOE + USISWRST + USIPE6 + USIPE7;
	USICTL1 	= USICKPH + USIIE;
	USICKCTL 	= USIDIV_0 + USISSEL_2;
	USISR		= 0x0000;
	USICTL0 	&= ~USISWRST;
	USICTL1 	&= ~USIIFG;

}

void conf_ADC10(void)
{
	ADC10CTL1 = INCH_0 + ADC10DIV_0 + ADC10SSEL1 ; // Channel 0, ADC10CLK = MCLK
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON + ADC10IE; //Vcc & Vss as reference
	ADC10AE0 |= BIT0; //P1.0 ADC option
}

void conf_TA0(void)
{
	TA0CCR0 = 10000;		                	// TAIFG on around ~ 3s
	TA0CTL  = TASSEL_1 + MC_1 + TACLR;		// SMCLK, upmode, TA0 interrupt ON
	TACCTL0 = CCIE;
}

void nRF24L01_init(void)
{
	set_status(EN_AA, ENAA_P0);					//enable auto-ack para pipe0
	set_status(EN_RXADDR, ERX_P0);				//enable datapipe 0
	set_status(SETUP_AW, 0x03);					//address width de 5 bytes (en el receptor deben se igual)
	set_status(RF_CH, 0x05);					//configuramos la frecuencia en 2,405 GHz
	set_status(RF_SETUP, RF_PWR1 );				//0dBm y 2Mbps
	set_status(RF_SETUP, RF_PWR2 );				//0dBm y 2Mbps
	static uint8_t dir [5] = {0};
	for( i=0 ; i<5 ; i++)
	{
		dir[i] = 0xE7;
	}
	set_dir(TX_ADDR, dir, 5);
	set_status(CONFIG, ~MASK_MAX_RT);			//activo la interrupcion por max envios, interrupcion activa por bajo
	set_status(CONFIG, ~MASK_TX_DS);			//activo la interrupcion por envio de paquete, interrupcion activa por bajo
	set_status(CONFIG, PWR_UP);					// nRF en modo standby

}


void set_dir(uint8_t registro, uint8_t *valor, uint8_t len)
{
	registro = registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_15US);
	for( i=0 ; i<len ; i++)
	{
		spi_transfer(valor[i]);
	}
	CSN_DIS;
}

uint8_t spi_transfer(uint8_t dato)
{
	USISRL	= dato;
	USICNT 	= 8;            // Start SPI transfer
	while ( !(USICTL1 & USIIFG) );
	USICTL1 &= ~USIIFG;
	return USISRL;
}

uint16_t spi_transfer16(uint16_t dato)
{
	USISR	= dato;
	USICNT 	= 16 | USI16B;
	while ( !(USICTL1 & USIIFG) );
	USICTL1 &= ~USIIFG;
	return USISR;
}

void write_reg(uint8_t registro, uint8_t valor)
{
	registro = registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_15US);
	spi_transfer(valor);
	CSN_DIS;
}

uint8_t read_reg(uint8_t registro)
{
	uint8_t ret;
	registro = registro | R_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_15US);
	ret = spi_transfer(NOP);
	CSN_DIS;
	return ret;
}

void set_status(uint8_t registro, uint8_t parametro)
{
	uint8_t estado;
	estado = read_reg(registro);
	//Logica de enmascaramiento
	if ( ( parametro <= 0x80 ) && ( parametro != 0x7f ) ){
		estado |= parametro;
	}
	else {
		estado &= parametro;
	}

	write_reg(registro, estado);
}

void enviar_dato(uint16_t dat)
{
	uint8_t status;
	CSN_EN;
	spi_transfer(W_TX_PAYLOAD);
	spi_transfer16(dat);
	CSN_DIS;
	CE_EN;
	__delay_cycles(DELAY_CYCLES_15US);
	CE_DIS;
	__bis_SR_register(LPM3_bits + GIE);//entro en LPM3 y espero la int por parte del nRF, sea TX_DS o MAX_TX_DS
	status = read_reg(STATUS);
	if(status & TX_DS) {
		set_status(STATUS, TX_DS); // se envi� el paquete.
	} else {
		set_status(STATUS, MAX_RT); //aca se puede avisar o contar que no se envi� el paquete, o algo.
	}
}

//Port 1.3 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	P1OUT	^=	 BIT4;
}

