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
      // Initial value of PORTB is 0b00000000
      // We need to make it 0b00000001 and this can be done as follows.
      // PORTB = PORTB OR 0b00000001
      // PORTB = PORTB OR (1 << 0) (one is left shifted by 0 bits => 1)
      // PORTB = PORTB OR (1 << PINB0);
      // PORTB = PORTB | (1 << PINB0); (same as a += 1 incrementing)
      PORTB |= (1 << PINB0);

      // Define the duration of the HIGH state in Milli seconds. 1000 ms = 1 s
      _delay_ms(100);

      // Make the PINB0 port low to turn the LED off.
      // Current  value of the PORTB register is 0b00000001
      // We need to make it all zeros to get the PINB0  to LOW state
      // This can easily be done by taking the Logical AND with 0b11111110
      // PORTB = PORTB AND 0b11111110;
      // PORTB = PORTB AND NOT(0b00000001)
      // PORTB = PORTB AND NOT(1 << 0)
      // PORTB = PORTB AND NOT(1 << PINB0)
      // PORTB = PORTB & ~(1 << PINB0)
      PORTB &= ~(1 << PINB0);

      // Define the duration of the LOW state.
      _delay_ms(100);
    }
}

/*
Note:

Registers like DDRB, PORTB have the 0x00/0b00000000 as their initial value.
DDRB = 0b00000000;
If we need to change the bit value of only one bit of the register, it can be
easily done using left shift bitwise operator.

Say we need to set the data direction of the PINB0 to be output.
For that we need to set DDRB0 to 1.
After assigning this value to that bit, the DDRB register will look like
DDRB = 0b00000001

To obtain this we can simply do the following.
DDRB = 0b00000000 OR 0b00000001;(Logical or operator)

This can be done efficiently as follows.
DDRB = DDRB OR (0b00000001 << 0); (0b00000001 is shifted left by zero bits.)
DDRB = DDRB OR (1 << 0);

Instead of 0 we can represent this by pin position easily.
0 corresponds to the PINB0 and therefore,
DDRB = DDRB OR (1 << PINB0);

Therefore,
DDRB = DDRB | (1 << PINB0);
DDRB |= (1 << PINB0);
*/
