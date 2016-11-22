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
	//conf_TA0		();				   // Configura TimerA TA0

	volatile uint8_t estado;
	estado = read_reg(SETUP_AW);


	while (1)
	{
		//__bis_SR_register(LPM3_bits + GIE);
		ADC10CTL0 |= ENC + ADC10SC; // Sampling and conversion start
		//__bis_SR_register(LPM3_bits + GIE);
		__delay_cycles(DELAY_CYCLES_5MS);
		dat = ADC10MEM;
		P1OUT	^=	 BIT4;
		enviar_dato(dat);
		__delay_cycles(50000);

		/*TA0CCR0 = 10000;
		TA0CTL  = TASSEL_1 + MC_1 + TACLR;
		TACCTL0 = CCIE;
*/
	}
}
