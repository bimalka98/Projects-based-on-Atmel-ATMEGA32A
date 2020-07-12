/*
  * Interfacing a 16*2 LCD display through I2C
  * Created   : 7/12/2020 3:44:42 PM
  * Author    : Bimalka Piyaruwan Thalagala
  * Function  : Change_light_intensity_using_PWM.
  */


#include <avr/io.h>


int main(void)
{
    // Data need to be in "char" data type to display through the LCD.
    // Define a global variable to hold a char data.
    char first_name = "Bimalka";
    char last_name = "Piyaruwan";

    // Initialize the LCD to display
    lcd_init(LCD_BACKLIGHT_ON);
    lcd_cursorOFF();


    while (1)
    {
      // Calling the function to display the char defined previously.
      lcd_puts(first_name);
      /*
      The LCD can display only 16 characters in a single line.
      If the defined text overflows 16 characters,
      Cursor of the LCD must be moved to the beginning of the next line.
      */
      // To move the cursor to the beginning of the next line
      lcd_goto_xy(0,1);

      // Calling the function to display the second char object.
      lcd_puts(last_name);
    }
}
