/*
 * funciones.h
 *
 *  Created on: 24/8/2016
 *      Author: Alejandro
 */

#include <msp430.h>
#include <stdint.h>


#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void conf_WDT(void);
void conf_CLK(void);
void conf_IO(void);
void conf_USI(void);
void conf_ADC10(void);
void conf_TA0(void);
void nRF24L01_init(void);
uint8_t spi_transfer(uint8_t dato);
void write(uint8_t registro, uint8_t valor);
void read(void);


#endif /* FUNCIONES_H_ */
