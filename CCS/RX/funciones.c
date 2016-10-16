/*
 * funciones.c
 *
 *  Created on: 22/8/2016
 *      Author: Alejandro
 */

#include "funciones.h"
#include "variables.h"

uint8_t i = 0;

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
	P1SEL  	&= 	~(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7); //con un 0 en el bit configuro el pin como GPIO
	P1DIR	|=  BIT0 + BIT1 + BIT2 + BIT5 + BIT6; //los demas como entrada (0)
	//P1IE 	|= 	BIT3;                    // P1.3 interrupt enabled
	//P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	P1OUT	&=	~BIT1;						// nRF24L01+ desactivado
}

void conf_USI(void)
{
	USICTL1 	&= ~USII2C; // Funcionamiento en modo SPI
	USICTL0		|= USIMST; //Funcionamiento en modo master
	USICTL1 	&= ~USIIFGCC; // Resetea USIIFG cuando USICNT llega a 0
	USICTL0		|= USISWRST; // Software reset
	USICTL0		|= USIPE5 + USIPE6 + USIPE7; // Activa funcionalidad de los puertos (P1.5->SCLK, P1.6->SDO, P1.7->SDI)
	USICTL0		|= USIOE;
	USICTL1 	|= USIIE;
	USICKCTL 	|= USIDIV_2 + USISSEL_2; // SMCLK como clock source (no usar sin "_" porque son otros macros, ver user's guide)
	USICKCTL	&= ~USICKPL; // Nivel inactivo en bajo
	USICTL1		|= USICKPH; // Captura en flanco ascendente y cambia en descendente
	USISR		= 0x0000;
	USICTL0 	&= ~USISWRST;
	USICTL1 	&= ~USIIFG;

}

void conf_ADC10(void)
{
	ADC10CTL1 = INCH_0 + ADC10DIV_0 + ADC10SSEL1 ; // Channel 0, ADC10CLK = MCLK
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON + ADC10IE; //Vcc & Vss as reference
	ADC10AE0 |= BIT4; //P1.4 ADC option
}

void conf_TA0(void)
{
	TA0CCR0 = 36000;		                	// TAIFG on around ~ 3s
	TA0CTL  = TASSEL_2 + MC_1 + TACLR;			// SMCLK, upmode, TA0 interrupt ON
	TACCTL0 = CCIE;
}

void nRF24L01_init(void)
{
	set_status(CONFIG, PRIM_RX);				// nRF en modo RX
	set_status(EN_AA, ~ENAA_P0);					//enable auto-ack para pipe0
	set_status(EN_RXADDR, ERX_P0);				//enable datapipe 0
	set_status(EN_RXADDR, ~ERX_P1);				//disable datapipe 1
	set_status(SETUP_AW, 0x03);					//address width de 5 bytes (en el transmisor debe ser igual)
	set_status(RF_CH, 0x01);					//configuramos la frecuencia en 2,401 GHz
	set_status(RF_SETUP, ~RF_DR );				//0dBm y 2Mbps
	set_status(RF_SETUP, RF_PWR1 );				//0dBm y 2Mbps
	set_status(RF_SETUP, RF_PWR2 );				//0dBm y 2Mbps
	//static uint8_t l_addr = 5;				//Problemas con la declaraci�n de l_addr y el vector dir
	static uint8_t dir[5] = {0};
	for(i=1; i<5; i++)
	{
		dir[i] = 0xE7;
	}
	set_dir(RX_ADDR_P0, dir, 5);
	set_status(RX_PW_P0, 0x02);					//datos de 2 bytes
	//set_status(CONFIG, MASK_RX_DR);				//desactivo la interrupci�n en IRQ
	set_status(CONFIG, PWR_UP);					// nRF en modo standby

}


void set_dir(uint8_t registro, uint8_t *valor, uint8_t len)
{
	registro = registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_5MS);
	for(i=0; i<len; i++)
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
	//uint8_t ret;
	registro = registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_5MS);
	spi_transfer(valor);
	CSN_DIS;
}

uint8_t read_reg(uint8_t registro)
{
	uint8_t ret;
	registro = registro | R_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_5MS);
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

uint8_t flag_RX(void)
{
	uint8_t ret;
	ret = read_reg(STATUS);
	ret &= RX_DR;
	return ret;
}



