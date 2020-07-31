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
    	DDRD = 0x00; PORTD = 0xFF;
	DDRB = 0xFE; PORTB = 0x00;

	/* Insert your solution below */
    	while (1) {	

		unsigned char dInput = PIND & 0xFF;
		unsigned char bInput = PINB & 0x01;
		unsigned char airbagSensor = 0x00;
		unsigned short weight = ((dInput << 1) | bInput);

		if(weight > 0x45){
			airbagSensor = 0x02;
		}
		else if( (weight > 0x05) && (weight < 0x46) ){
			airbagSensor = 0x04;
		}
		else{
			airbagSensor = 0x00;
		}

		PORTB = airbagSensor;
    	}	
    	return 1;
}
