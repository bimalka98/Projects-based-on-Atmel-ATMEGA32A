/*
 * Change_light_intensity_using_PWM
 * Created: 6/25/2020 3:03:22 PM
 * Author : Bimalka Piyaruwan Thalagala
 * Function : Change_light_intensity_using_PWM.
Connect the LED to the OC0(PB3) pin through a current limiting resistor.

 */

//Define the clock rate in order to use the delay functions within the code.
#ifndef F_CPU
#define F_CPU 1000000UL
#endif

// Include necessary header files
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    //Declare the data direction of the PB3 pin as an output.
    //All the registers have 0x00 as their initial value.
    //We only need to set the corresponding bit to PINB3 HIGH, to make it an output.
    // This can be done using left shift operator and OR operator as following.
    DDRB |= (1 << PINB3);

    // Configuring the Time Counter Control Register BITS.
    // TCCR0 = 0x00 initially
    // "Waveform Generation Mode" for "Fast PWM" Mode.
    TCCR0 |= (1 << WGM01) | (1 << WGM00);

    // "Compare Output Mode" for "Fast PWM" Mode.
    // Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
    TCCR0 |= (1 << COM01);

    // Clock Selection for clock without prescaling.
    // Timer starts counting at the moment this is defined.
    TCCR0 |= (1 << CS00);

    //Declare a Global Variable to store the value corresponding to the brightness of the LED.
    int brightness;
    int delay = 10; // In milliseconds

    while (1)
    {


      // Increase the brightness of the LED
      for(brightness = 0; brightness < 256; brightness++)
      {
        OCR0 = brightness;
        _delay_ms(delay);
      }

      // Decrease the brightness of the LED
      for(brightness = 255; brightness >=0; brightness--)
      {
        OCR0 = brightness;
        _delay_ms(delay);
      }
    }
}
