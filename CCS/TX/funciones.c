/*
 * funciones.c
 *
 *  Created on: 22/8/2016
 *      Author: Alejandro
 */

#include "funciones.h"
#include "variables.h"


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
	P1IE 	|= 	BIT3;                    // P1.3 interrupt enabled
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	P1OUT	&=	~BIT1;						// nRF24L01+ desactivado
}

void conf_USI(void)
{
	USICTL0		= USIPE5 + USIMST + USIOE + USISWRST + USIPE6 + USIPE7;
	USICTL1 	= USICKPH + USIIE;
	USICKCTL 	= USIDIV_0 + USISSEL_2;
	USISR		= 0x0000;

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
	TA0CTL  = TASSEL_2 + MC_1 + TACLR;	// SMCLK, upmode, TA0 interrupt ON
	TACCTL0 = CCIE;
}
USI16B
void nRF24L01_init(void)
{
	write(CONFIG, PWR_UP);		// nRF en modo standby
	write(EN_AA, ENAA_P0);		//enable auto-ack
	write(EN_RXADDR, ERX_P0);	//datapipe 0
	write(SETUP_AW, 0x03);		//address width de 5 bytes (en el receptor deben se igual)
	write(RF_CH, 0x05);			//configuramos la frecuencia en 2,405 GHz
	write(RF_SETUP, RF_PWR1 + RF_PWR2 );	//0dBm y 2Mbps



}

uint16_t spi_transfer(uint16_t dato)
{
	USISR	= dato;
	USICNT 	= 16 | USI16B;            // Start SPI transfer
	while ( !(USICTL1 & USIIFG) );
	return USISR;
}


void write(uint8_t registro, uint8_t valor)
{
	uint8_t ret;
	registro=registro | W_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_5MS);
	spi_transfer(valor);
	CSN_DIS;
}

uint8_t read(uint8_t registro)
{
	uint8_t ret;
	registro=registro | R_REGISTER;
	CSN_EN;
	spi_transfer(registro);
	__delay_cycles(DELAY_CYCLES_5MS);
	ret = spi_transfer(NOP);
	CSN_DIS;
	return ret;
}







