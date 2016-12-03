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
uint16_t spi_transfer16(uint16_t dato);
void enviar_dato(uint16_t dato);
void write_reg(uint8_t registro, uint8_t valor);
uint8_t read_reg(uint8_t registro);
void set_status(uint8_t registro, uint8_t parametro);
void set_dir(uint8_t registro, uint8_t *valor, uint8_t len);
void enviar_paq(void);
void adc_sam16(void);




//void Timer_A(void) 		__attribute__((interrupt(TIMERA0_VECTOR)));
//void Port_1(void) 		__attribute__((interrupt(PORT1_VECTOR)));
//void ADC10(void) 		__attribute__((interrupt(ADC10_VECTOR)));


#endif /* FUNCIONES_H_ */
