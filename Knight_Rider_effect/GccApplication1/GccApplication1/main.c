/*
 * Created: 6/24/2020 1:01:06 AM
 * Last Modified: 6/24/2020 4:24:45 PM
 * Author : Bimalka Piyaruwan Thalagala
 * This project is an extension of Blink_an_LED project,
 where 8 LEDs are used to generate the knight rider pattern.
 The logic used in turning the LED on and off is explained in Blink_an_LED project.

In this implementation of knight rider effect with 8 LEDs,
PORTB is used to connect the 8 LEDs and every LED is connected
through a current limiting resistor of 220 ohms.
 */

 // In order to use the delay function F_CPU must be defined at first.
 #ifndef F_CPU
 #define F_CPU 1000000UL
 #endif

// Include the necessary header files
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    // Configuring the data direction of the PORTB.
    // All the pins are output pins and therefore set to one.
    // DDRB |= 0b11111111;
    //In hexadecimal mode this can easily be written as 0xFF;
    DDRB |= 0xFF;

	  // Define the on time of an LED in ms.
	  int delay = 50;

    // In order to represent the knight rider effect,
    // Only one LED must be lit at a time
    // And the direction of propagation should be altered at the end of evry loop.


    while (1)
    {

	// Forward propagation loop
	// All the LEDs are lit one at a time in order.
  // From PINB0 to PINB7.
	for (int i = 0; i <=7; i++)
	{
		PORTB |= (1 << i);
		_delay_ms(delay); //LED on time.
		PORTB &= ~(1 << i);
	}


	// Backward Propagation loop.
	// Here in this loop LED s at the two ends are not used.
  // LEDs from PINB6 to PINB1 are lit one at a time.
	for (int i = 6; i > 0; i--)
	{
		PORTB |= (1 << i);
		_delay_ms(delay); //LED on time.
		PORTB &= ~(1 << i);
	}

    }
}
