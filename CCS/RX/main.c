#include <msp430.h> 
#include "funciones.h"
/*
 * main.c
 */
int main(void) {

	conf_WDT      	();                // Configura WDT del sistema
	conf_CLK      	();                // Configura CLK del sistema
	conf_IO       	();                // Configura Entradas/Salidas
	conf_USI   		();                // Configura USCI_B0 --> SPI
	nRF24L01_init 	();				   // Configura nRF24L01+
	conf_TA0		();				   // Configura TimerA TA0
	//P1OUT	^=	 BIT0;

	
	return 0;
}
