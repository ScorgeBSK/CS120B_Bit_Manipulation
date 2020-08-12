/*	Author: Trung Lam
 *  Partner(s) Name: None 
 *	Lab Section: B22
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    	while (1) {
		
		unsigned char tmpA = PINA & 0xFF;
		unsigned char tmpB = PINB & 0xFF;
		
		unsigned char counter = 0x00;
		unsigned char iterator = 0x01;

		for(int i = 0; i < 8; ++i){
	
			if(tmpA & iterator){
				counter++;
			}

			if(tmpB & iterator){
				counter++;
			}

			iterator++;
		}

		PORTC = counter;

    	}	
    	return 1;
}
