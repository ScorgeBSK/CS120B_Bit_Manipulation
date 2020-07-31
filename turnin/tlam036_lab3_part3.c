/*	Author: Trung Lam
 *  Partner(s) Name: None 
 *	Lab Section: B22
 *	Assignment: Lab #3  Exercise #3
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
		
		unsigned char tmpA = PINA & 0x7F;
		unsigned char tmpC = 0x00;
		unsigned char fuelSensor = (tmpA & 0x0F);

		if( (tmpA & 0x10) && (tmpA & 0x20) && !(tmpA & 0x40) ){
			tmpC = (tmpC | 0x80);
		}	
	
		if(fuelSensor < 0x05){
			tmpC = (tmpC | 0x40);
		}

		if( (fuelSensor < 0x10) && (fuelSensor > 0x0C) ){
			tmpC = (tmpC | 0x3F);
		}

		else if( (fuelSensor < 0x0D) && (fuelSensor > 0x09) ){
			tmpC = (tmpC | 0x3E);
		}

		else if( (fuelSensor < 0x0A) && (fuelSensor > 0x06) ){
			tmpC = (tmpC | 0x3C);
		}

		else if( (fuelSensor < 0x07) && (fuelSensor > 0x04) ){
			tmpC = (tmpC | 0x38);
		}	

		else if( (fuelSensor == 0x03) || (fuelSensor == 0x04) ){
			tmpC = (tmpC | 0x30);
		}

		else if( (fuelSensor == 0x01) || (fuelSensor == 0x02)) {
			tmpC = (tmpC | 0x20);
		}

		PORTC = tmpC;

    	}	
    	return 1;
}
