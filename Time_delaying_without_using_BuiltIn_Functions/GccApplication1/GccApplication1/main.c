/*
 * Time delaying without using built-in functions
 *
 Functioal Description :  In this implementation of the time delaying,
 the 8-bit TCNT0 timer/counter register is used to count the clock ticks.
 And the clock is used with a prescaling rather than using the original
 clock frequency in order to increse the time taken to overflow.
 Because with this TCNT0 timer the maximum ticks are limited to 255 as
 it is an 8 bit register.

 * Created: 6/25/2020 9:55:54 PM
 * Author : Bimalka Piyaruwan Thalagala
 */

// Let's define the clock frequency to be 1 MHz.

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

/*
This means clock ticks 1000000 times per second.
But counter is able to count 255 ticks as it is an 8-bit register.
And counter increments its value by 1 in every microsecond if we don't
scale it. And maximum countable time will be 255 microseconds without
any overflow.

Consider we use the maximum scling factor of 1024 by setting
the Clock Select bits in TCCR0 register to `101`. At the moment
this is set TCNT0 register starts couting the ticks.

Then clock = clock/1024 = 1000000/1024 = 976.5625 Hz
Therefore clock cycles time = 1/ 976.5625 = 1.024 ms
TCNT0 will be incremented by one in every  1.024 ms.

Therefore maximum delay we can obtain without any overflow
is 255*1.024 ms 261.12 ms which is much less than one second.

Imagine we need to get a delay of one second. Then number of overflows
that can happen in one second is 1 second / 261.12 milliseconds = 3.82966
Therefore at least 4 overflows need to happen in order to get a delay
of one second.

*/

#include <avr/io.h>

//Calling the function defined at the end
void delay();

int main(void)
{
    // To recognize what is going on we can ckeck the desired
    // behaviour using an LED.
    DDRB |= (1 <<PINB0);

    while (1)
    {
      PORTB |= (1 << PINB0); // Turn the LED on
      // lOOP FOR THE DELAY.
      delay();
      PORTB &= ~(1 << PINB0); // Turn the LED off
      // lOOP FOR THE DELAY.
      delay();
    }
}


// Function to generate 1 second delay.
void delay(){
  // Prescaling the clock and initiate the counting.
  TCCR0 =  0b00000101;
  //Define a variable to hold the number of overflows
  int overflowCount = 0;
  // lOOP FOR THE DELAY.
  // Need to identify 4 overflows
  while (overflowCount < 5)
  {
    // From the moment we configure TCCR0, TCNT0 counts.

    // The TCNT0 is incremented until any overflow happens.
    // When an overflow happens Timer Overflow Flag(TOV0)
    // in TIFR is automatically set to 1.
    // This can be used to identify an overflows.
    while ((TIFR & 0X01) == 0);
    // When an overflow happens TIFR => 0x01 and above while loop stops.

    // Now we need to Reset the TOV0 flag back to zero in order to
    // identify another overflow.
    // Unlike other registers, in order to reset it to zero,
    // We need to make it one. Not zero.
    TIFR = 0x01;

    // Increment the overflowCount until we get 4 overflows.
    overflowCount++;
  }
    // TCNT0 begins counting when we configure the TCCR0.
    // In order to strat counting again from the beginning,
    //  TCCR0 must be set to its initial value. ie.0x00.
  TCCR0 =  0x00;
}
