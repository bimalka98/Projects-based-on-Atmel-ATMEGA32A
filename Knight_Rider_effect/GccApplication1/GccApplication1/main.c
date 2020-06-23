/*
 * Created: 6/24/2020 1:01:06 AM
 * Author : Bimalka Piyaruwan Thalagala
 * This project is an extension of Blink_an_LED project,
 where 8 LEDs are used to generate a pattern.

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


    // In order to represent the knight rider effect,
    // Only one LED must be lit at a time
    // And the direction of propogation should be altered,

    while (1)
    {
      PORTB |= 0b00000001;
    }
}
