/*
 * Change_light_intensity_using_PWM
 * Created: 6/25/2020 3:03:22 PM
 * Author : Bimalka Piyaruwan Thalagala
 */


#include <avr/io.h>
#include <util/delay.h>

void InitPWM()
{

}

int main(void)
{

    while (1)
    {
    }
}



















/*
#define F_CPU 8000000UL
#include "avr/io.h"
#include <util/delay.h>

void PWM_init()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
	DDRB|=(1<<PB3);	/*set OC0 pin as output*/
}


int main ()
{
	unsigned char duty;

	PWM_init();
	while (1)
	{
		for(duty=0; duty<255; duty++)
		{
			OCR0=duty;			/*increase the LED light intensity*/
			_delay_ms(8);
		}
		for(duty=255; duty>1; duty--)
		{
			OCR0=duty;			/*decrease the LED light intensity*/
			_delay_ms(8);
		}
	}
}

*/
