#include <msp430.h> 
#include "funciones.h"
#include "variables.h"
/*
 * main.c
 */

uint16_t dato;
uint16_t mensaje;

void main(void) {

	conf_WDT      	();                // Configura WDT del sistema
	conf_CLK      	();                // Configura CLK del sistema
	conf_IO       	();                // Configura Entradas/Salidas
	conf_USI   		();                // Configura USCI_B0 --> SPI

	__delay_cycles(DELAY_CYCLES_100MS);

	write_reg(STATUS, 0x70);		//Reset nRF24l01+
	nRF24L01_init 	();				   // Configura nRF24L01+
	//P1OUT	^=	 BIT0;
	CE_EN;
	__delay_cycles(DELAY_CYCLES_130US);
	mensaje=0x0000;
	while (1)
	{

		mensaje = read_reg(STATUS);
		mensaje &= RX_DR;
		dato = 0x0000;

		if(mensaje==0x0040){
			CE_DIS;
			spi_transfer (R_RX_PAYLOAD);
			dato = spi_transfer16 (NOP16);
			//preguntar si hay mas en la FIFO?
			set_status (STATUS , RX_DR);
			P1OUT	^=	BIT0;
			CE_EN;
		}

	}

	
}
