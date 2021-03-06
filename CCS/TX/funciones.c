/*
 * funciones.c
 *
 *  Created on: 22/8/2016
 *      Author: Alejandro
 */

#include "funciones.h"
#include "variables.h"

uint16_t adc[16] = {0}; //Sets up an array of 32 integers and zero's the values

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

	P1REN |= BIT3;                 // Enable internal pull-up/down resistors
	P1OUT |= BIT3;                 //Select pull-up mode for P1.3

	P1IE 	|= 	BIT3;                    // P1.3 interrupt enabled
	P1IES 	|= 	BIT3;                    // P1.3 interrupt activa por flanco descendente
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	P1OUT	&=	~BIT1;						// nRF24L01+ desactivado
	P1OUT	&=	~BIT4;
	P1SEL	|=	BIT0;
}

void conf_USI(void)
{
	USICTL1 	&= ~USII2C; // Funcionamiento en modo SPI
	USICTL0		|= USIMST; //Funcionamiento en modo master
	//USICTL1 	&= ~USIIFGCC; // Resetea USIIFG cuando USICNT llega a 0
	USICTL0		|= USISWRST; // Software reset
	USICTL0		|= USIPE5 + USIPE6 + USIPE7; // Activa funcionalidad de los puertos (P1.5->SCLK, P1.6->SDO, P1.7->SDI)
	USICTL0		|= USIOE;
	//USICTL1 	|= USIIE;
	USICKCTL 	|= USIDIV_2 + USISSEL_2; // SMCLK como clock source (no usar sin "_" porque son otros macros, ver user's guide)
	USICKCTL	&= ~USICKPL; // Nivel inactivo en bajo
	USICTL1		|= USICKPH; // Captura en flanco ascendente y cambia en descendente
	USICNT		&= ~USI16B;
	//USISR		= 0x0000;
	USICTL0 	&= ~USISWRST;
	USICTL1 	&= ~USIIFG;

}

void conf_ADC10(void)
{
	//ADC10CTL1 = INCH_10 + ADC10DIV_0 + ADC10SSEL1 ; // Input=temp sensor, Channel 0, ADC10CLK = MCLK (DIVIDER = 0)
	//ADC10CTL0 = SREF_0 + ADC10SHT_0  + ADC10ON + ADC10IE; //Vcc & Vss as reference, ADC10 sample-and-hold time = 4 � ADC10CLKs
	//ADC10AE0 |= BIT0; //P1.0 ADC option
	ADC10CTL1 = INCH_10 + ADC10DIV_0 + ADC10SSEL1 + CONSEQ_2; 	// Input=temp sensor, Channel 0, ADC10CLK = MCLK (DIVIDER = 0), Repeat-SingleChannel
	ADC10CTL0 = SREF_0 + ADC10SHT_0  + ADC10ON + ADC10IE + MSC; //Vcc & Vss as reference, ADC10 sample-and-hold time = 4 � ADC10CLKs, Multiple Sample Conversion
	ADC10DTC1 = 0x10;											// 32 conversions
}

void adc_sam16(void)
{
    ADC10CTL0 &= ~ENC;				// Disable Conversion
    while (ADC10CTL1 & BUSY);		// Wait if ADC10 busy
    ADC10SA = (int)adc;				// Transfers data to next array (DTC auto increments address)
    ADC10CTL0 |= ENC + ADC10SC;		// Enable Conversion and conversion start
    __bis_SR_register(LPM3 + GIE);// Low Power Mode 0, ADC10_ISR
}

void conf_TA0(void)
{
	TA0CCR0 = 10000;		                	// TAIFG on around ~ 3s
	TA0CTL  = TASSEL_1 + MC_1 + TACLR;			// SMCLK, upmode, TA0 interrupt disabled
	TACCTL0 = CCIE;								//enable timer interrupt
}

void nRF24L01_init(void)
{
	set_status(EN_AA, ~ENAA_P0);				//~enable auto-ack para pipe0
	set_status(EN_RXADDR, ERX_P0);				//enable datapipe 0
	set_status(SETUP_AW, 0x03);					//address width de 5 bytes (en el receptor deben se igual)
	set_status(RF_CH, 0x01);					//configuramos la frecuencia en 2,405 GHz
	set_status(RF_SETUP, RF_PWR1 );				//0dBm y 2Mbps
	set_status(RF_SETUP, RF_PWR2 );				//0dBm y 2Mbps
	set_status(RF_SETUP, ~RF_DR );				//0dBm y 2Mbps
	static uint8_t dir [5] = {0};
	for( i=0 ; i<5 ; i++)
	{
		dir[i] = 0xE7;
	}
	set_dir(TX_ADDR, dir, 5);
	set_status(RX_PW_P0, 0x20);
	set_status(CONFIG, MASK_MAX_RT);			//desactivo la interrupcion por max envios, interrupcion activa por bajo
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
	dato	=	USISR;
	USICNT 	&= ~USI16B;
	return dato;
}

void write_reg(uint8_t registro, uint8_t valor)
{
	registro = registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	spi_transfer(valor);
	CSN_DIS;
	__delay_cycles(DELAY_CYCLES_5MS);
}

uint8_t read_reg(uint8_t registro)
{
	uint8_t ret;
	registro = registro | R_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	ret = spi_transfer(NOP);
	CSN_DIS;
	__delay_cycles(DELAY_CYCLES_5MS);
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
	volatile uint8_t estado;
	CSN_EN;
	spi_transfer(FLUSH_TX);
	CSN_DIS;

	CSN_EN;
	spi_transfer(W_TX_PAYLOAD);
	spi_transfer16(dat);
	CSN_DIS;

	CE_EN;
	__delay_cycles(DELAY_CYCLES_15US);
	CE_DIS;

	__bis_SR_register(LPM3_bits + GIE);//entro en LPM3 y espero la int por parte del nRF, sea TX_DS

	status = read_reg(STATUS);
	status=status & TX_DS;
	while(status != TX_DS){
		status = read_reg(STATUS);
		status=status & TX_DS;
	}
	write_reg(STATUS,0x70);
}

void enviar_paq(void){
	uint8_t status;
	CSN_EN;
	spi_transfer(FLUSH_TX);
	CSN_DIS;

	CSN_EN;
	spi_transfer(W_TX_PAYLOAD);
	for( i=0 ; i<16 ; i++ )
	{
		spi_transfer16(adc[i]);
	}
	CSN_DIS;

	CE_EN;
	__delay_cycles(DELAY_CYCLES_15US);
	CE_DIS;

	__bis_SR_register(LPM3_bits + GIE);//entro en LPM3 y espero la int por parte del nRF, sea TX_DS
	status = read_reg(STATUS);
	status=status & TX_DS;
	while(status != TX_DS){
		status = read_reg(STATUS);
		status=status & TX_DS;
	}
	write_reg(STATUS,0x70);
}

//Timer A0 interrupt service routine
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	TA0CTL  &= ~TAIFG;
}

//ADC interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10 (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	ADC10CTL0 &= ~ADC10IFG;
}

//Port 1.3 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
}

