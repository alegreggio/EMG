#include <msp430.h> 
#include <stdint.h>
#include "funciones.h"
#include "variables.h"

/*
 * main.c
 */
void main(void) {

	conf_WDT      	();                // Configura WDT del sistema
	conf_CLK      	();                // Configura CLK del sistema
	conf_IO       	();                // Configura Entradas/Salidas
	conf_USI   		();                // Configura USCI_B0 --> SPI
	nRF24L01_init 	();				   // Configura nRF24L01+
	conf_ADC10 		();				   // Configura ADC10 ( P1.4 como entrada )
	conf_TA0		();				   // Configura TimerA TA0

	__enable_interrupt();

	while (1)
	{
		__bis_SR_register(LPM3_bits + GIE);


		ADC10CTL0 |= ENC + ADC10SC; // Sampling and conversion start
		__bis_SR_register(LPM3_bits + GIE);

		dat = ADC10MEM;
		P1OUT	^=	 BIT4;
		enviar_dato(dat);

		TA0CCR0 = 10000;
		TA0CTL  = TASSEL_1 + MC_1 + TACLR;
		TACCTL0 = CCIE;

	}
}



//Timer A0 interrupt service routine
#pragma vector=TIMERA0_VECTOR
__interrupt void Timer_A (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	//P1OUT	^=	 BIT4;

}

/*/Port 1.3 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	P1IFG 	&= 	~BIT3;               // P1.3 IFG cleared
	//P1OUT	^=	 BIT4;
}
*/
//ADC interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10 (void)
{
	_BIC_SR(LPM3_EXIT); // despierta del LPM3
	ADC10CTL0 = SREF_0 + ADC10SHT_3 + ADC10ON + ADC10IE; //Vcc & Vss as reference
	//P1OUT	^=	 BIT4;
}
