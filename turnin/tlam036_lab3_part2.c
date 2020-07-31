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
	DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    	while (1) {
		
		unsigned char tmpA = PINA & 0x0F;
		unsigned char tmpC = 0x00;

		if(tmpA < 0x05){
			tmpC = (tmpC | 0x40);
		}

		if( (tmpA < 0x10) && (tmpA > 0x0C) ){
			tmpC = (tmpC | 0x3F);
		}

		else if( (tmpA < 0x0D) && (tmpA > 0x09) ){
			tmpC = (tmpC | 0x3E);
		}

		else if( (tmpA < 0x0A) && (tmpA > 0x06) ){
			tmpC = (tmpC | 0x3C);
		}

		else if( (tmpA < 0x07) && (tmpA > 0x04) ){
			tmpC = (tmpC | 0x38);
		}	

		else if( (tmpA == 0x03) || (tmpA == 0x04) ){
			tmpC = (tmpC | 0x30);
		}

		else if( (tmpA == 0x01) || (tmpA == 0x02)) {
			tmpC = (tmpC | 0x20);
		}

		PORTC = tmpC;

    	}	
    	return 1;
}
