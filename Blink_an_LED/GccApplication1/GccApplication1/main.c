/*
 * Blink an LED using Atmel ATMEGA32A microcontroller
 * Created: 6/23/2020 9:04:03 PM
 * Author : Bimalka Piyaruwan Thalagala
 
Here PINB0 is used to connect the LED to the microcontroller through a current limiting resistor.
220 ohm resistor is used here. color code for resistors can be found at,
https://en.wikipedia.org/wiki/Electronic_color_code
And Cathode of the LED is directly connected to the one of the GND ports of the development board.
*/

// In order to use the delay function F_CPU must be defined at first.
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

// Include necessary header files.
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    // Configuring the data direction of the port to be used
    // To connect the LED.
    // Define the PINB0 as an output pin.
    DDRB |= (1 << PINB0);


    while (1)
    {
      // Make the PINB0 port high to light the LED
      PORTB |= (1 << PINB0);
      // Define the duration of the HIGH state in Milli seconds. 1000 ms = 1 s
      _delay_ms(100);
      // Make the PINB0 port low to turn the LED off.
      PORTB &= (0 << PINB0);
      // Define the duration of the LOW state.
      _delay_ms(100);
    }
}