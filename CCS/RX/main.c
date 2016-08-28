#include <msp430.h> 
#include "funciones.h"
/*
 * main.c
 */
int main(void) {

	uint8_t dato;

	conf_WDT      	();                // Configura WDT del sistema
	conf_CLK      	();                // Configura CLK del sistema
	conf_IO       	();                // Configura Entradas/Salidas
	conf_USI   		();                // Configura USCI_B0 --> SPI
	nRF24L01_init 	();				   // Configura nRF24L01+
	//P1OUT	^=	 BIT0;
	while (1)
	{
		CE_HIGH;
		while (!RX_DR);
		CE_LOW;
		spi_transfer (R_RX_PAYLOAD);



	}

	
	return 0;
}
