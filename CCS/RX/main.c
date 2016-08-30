#include <msp430.h> 
#include "funciones.h"
#include "variables.h"
/*
 * main.c
 */

uint16_t dato;

int main(void) {

	conf_WDT      	();                // Configura WDT del sistema
	conf_CLK      	();                // Configura CLK del sistema
	conf_IO       	();                // Configura Entradas/Salidas
	conf_USI   		();                // Configura USCI_B0 --> SPI
	nRF24L01_init 	();				   // Configura nRF24L01+
	//P1OUT	^=	 BIT0;
	while (1)
	{
		CE_EN;
		while (!flag_RX());
		dato = 0x0000;
		CE_DIS;
		spi_transfer (R_RX_PAYLOAD);
		dato = spi_transfer16 (NOP16);
		//preguntar si hay mas en la FIFO
		set_status (CONFIG , ~MASK_RX_DR);
	}

	
	return 0;
}
