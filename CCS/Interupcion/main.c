//******************************************************************************
// MSP430G2xx Demo - WDT, Low Power Mode, Interval Overflow ISR, DCO SMCLK
//
// Description: Go to LowPowerMode using software timed by the WDT ISR. The LED
// will turn off when sleeping, Port 1 interrupt will awake the mcu and turn on
// LED. The mcu will sleep at approximately 250 * 32ms based on default
// DCO/SMCLK clock source used in this example for the WDT.
// ACLK = n/a, MCLK = SMCLK = default
//
// MSP430G2xxx
// -----------------
// /|\| XIN|-
// | | |
// --|RST XOUT|-
// | |
// | P1.0|-->LED
//
// Aldo Briano
// Texas Instruments Inc.
// July 2010
//******************************************************************************
#include <msp430g2231.h>

unsigned int wdtCounter = 0;
void main(void)
{
	WDTCTL = WDT_MDLY_32; // Set Watchdog Timer interval to ~32ms
	IE1 |= WDTIE; // Enable WDT interrupt
	P1DIR |= BIT0; // Set P1.0 to output direction
	P1OUT |= BIT0; // Turn on LED at 1.0
	P1IE |= BIT3; // enable P1.3 interrupt
	__enable_interrupt();

	for(;;)
	{
	
	}
}

// Watchdog Timer interrupt service routine
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
	if(wdtCounter == 249)
		{
		P1OUT = 0x00; // P1.0 turn off
		wdtCounter = 0;
		_BIS_SR(LPM3_bits + GIE); // Enter LPM3 w/interrupt
		}
	else
		{
		wdtCounter++;
		}

	}
// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
	wdtCounter = 0; // reset watchdog timer counter
	P1OUT |= 0x01; // turn LED on
	P1IFG = 0x0;
	_BIC_SR(LPM3_EXIT); // wake up from low power mode

}
