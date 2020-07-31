/*	Author: Trung Lam
 *  Partner(s) Name: None 
 *	Lab Section: B22
 *	Assignment: Lab #3  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    	while (1) {	
		 
		unsigned char tmpB = 0x00;
		unsigned char upperA = PINA & 0xF0;
		unsigned char lowerA = PINA & 0x0F;

		tmpB = (upperA >> 4) | (lowerA << 4);		

		PORTB = tmpB;
    	}	
    	return 1;
}
