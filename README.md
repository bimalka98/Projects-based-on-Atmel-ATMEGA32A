## Note:
* Various Projects based on Atmel ATMEGA32A microcontroller are included in this repository.
* The Program related to each project can be viewed by clicking `View Code` given under each project.
* All the required information related to the microcontroller to understand the key concepts behind each project, are hyperlinked along with the project as `View Concept-<title>`.
* Each program is also explained deeply in the comments of the code.
* Guide to setup USBASP can be found [here](https://www.youtube.com/watch?v=kPcgjkQn2eE)

# *PROJECTS*

## 1. Blink an LED
#### [View Code](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Blink_an_LED/GccApplication1/GccApplication1/main.c)
#### [View Concept-Configuration of pins](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/README.md#configuration-of-pins)

## 2. Knight Rider Effect
#### [View Code](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Knight_Rider_effect/GccApplication1/GccApplication1/main.c)
#### [View Concept-Configuration of pins](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/README.md#configuration-of-pins)

## 3. Time delaying using TOV flag in TIFR
#### [View Code](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Time_delaying_using_TOV_in_TIFR/GccApplication1/GccApplication1/main.c)
#### [View Concept-Timers in ATMEGA32A](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/README.md#timers-in-atmega32a)

## 4. Change light intensity of an LED using Pulse Width Modulation(PWM)
#### [View Code](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Change_light_intensity_using_PWM/GccApplication1/GccApplication1/main.c)
#### [View Concept-PWM Signal Generation in ATMEGA32A](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/README.md#pwm-signal-generation-in-atmega32a)

## 5. Interfacing a 16*2 LCD display through I2C
#### [View Code](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Interfacing_an_LCD_display_through_I2C/GccApplication1/GccApplication1/main.c)
#### [View Concept](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/README.md#interfacing-a-162-lcd-display-through-i2c)

# 🔴🟡🟢 KEY CONCEPTS

# Pinout of the Atmel ATMEGA32A microcontroller
![pinout atmega](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Figures/Pinout.PNG)

## Configuration of pins

### Data Direction of a pin

* If set to logic 1 --> Output
* If set to logic 0 --> Input

In general,
```
n = {A, B, C, D}
DDRn | = 0bxxxxxxxx;
A register has 8 bits therefore every bit must be precisely configured. x can be either 0 or 1.

Else this can be done as follows

n = {A, B, C, D} and i = {0, 1, 2, 3, 4, 5, 6, 7}- the position of the pin in a given port
DDRn  | = (x << PINni);
```
Imagine we  need to configure the PINC0 to be an output pin and every other pin to be an input pin in that port, it can be done as follows.

```
DDRC | = 0b00000001;
or
DDRC | = (1 << PINC0);
```
### Logical state of a pin

* If set to logic 1 --> HIGH
* If set to logic 0 --> LOW

In general,
```
n = {A, B, C, D}, i = {0,1,2,3,4,5,6,7}

PORTn | = (1 << PINni);
This PORTn registers also contain 8 bits therefore every bit must be precisely configured if the binary format is used.
```

Imagine we need to make only the PINC0 HIGH. This can be done as follows. To make it LOW, code in the next line can be used.
```
PORTC | = (1 << PINC0);
PORTC & = ~(1 << PINC0);
```


## Timers in ATMEGA32A

ATMEGA32A has three timers.
* Timer 0  08-bit timer TCNT0, OCR0, TCCR0
* Timer 1  16-bit timer TCNT1, OCR1, TCCR1
* Timer 2  08-bit timer TCNT2, OCR2, TCCR2

*Each timer in ATMEGA32A is mainly associated with three different registers. Namely `TCNTn`(Timer Counter register) which counts the clock ticks, `OCRn`(Output Compare register) which is used to store some value to be compared with the TCNTn and finally the `TCCRn`(Timer Counter control register) which is used to configure the operation mode of the timer. The first three bits(2:0) in the TCCRn register are used to select the clock source and called `Clock Select(CS)` bits.*
```
TCCR0 Register

Bit           7     6     5      4    3     2     1   0
TCCR0         FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
Read/Write    W     R/W   R/W   R/W   R/W  R/W  R/W  R/W
Initial Value 0     0     0      0    0     0    0    0
```
Configuration of CS bits is done as follows.
```
CS02/CS01/CS00 Description
000 No clock source (Timer/Counter stopped because there is no clock source)
001 clk (No prescaling and take the oscillating frequency of the system clock source)
010 clk/8 (From prescaler)
011 clk/64 (From prescaler)
100 clk/256 (From prescaler)
101 clk/1024 (From prescaler)
110 External clock source on T0 pin. Clock on falling edge.
111 External clock source on T0 pin. Clock on rising edge.
```
All three timers are associated with one common register called `TIFR`(Timer/Counter Interrupt Flag Register).

* If TCNTn = OCRn then `OCFn`(output Compare Flag) in TIFR is set to 1
* If TCNTn overflows its maximum value then `TOVn`(Timer Overflow Flag) in TIFR is automatically set to 1. To clear this flag we need to set it to 1 not to 0.
```
TIFR Register

Bit             7    6    5     4    3    2    1    0
TIFR          OCF2 TOV2 ICF1 OCF1A OCF1B TOV1 OCF0 TOV0
Read/Write     R/W  R/W  R/W   R/W  R/W  R/W  R/W  R/W
Initial Value   0    0    0     0    0    0     0   0
```

## PWM Signal Generation in ATMEGA32A
*PWM is a method of getting an analog output(some value on a given range) using a digital signal which has only two states(HIGH/LOW). In ATMEGA32A there are 4 pins which can be used to generate PWM signals.*

### PWM supported pins

1. OC0   PB3
2. OC1A  PD5
3. OC1B  PD4
4. OC2   PD7

* Period of the PWM wave corresponds to  --> maximum value which can be stored in the 8 bit counter. i.e. 255
* Duty cycle corresponds to              --> Value specified in the Output Compare register(OCRn)

### Bit configuration of the TCCR0 register.
```
TCCR0 Register

Bit           7     6     5      4    3     2     1   0
TCCR0         FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
Read/Write    W     R/W   R/W   R/W   R/W  R/W  R/W  R/W
Initial Value 0     0     0      0    0     0    0    0
```
* Compare Output Mode for Fast PWM Mode- Bit 5:4

We need to set COM01 and COM00 bits to  `1 0 ` to get the required PWM output. In this configuration PWM signal output(0C0) becomes HIGH(5V) at the beginning(BOTTOM) of the TCNT0 counting cycle and PWM signal output(0C0) becomes LOW(0V) at the value specified in the OCR0(Output Compare register).
```
COM01 COM00 Description
  0     0     Normal port operation, OC0 disconnected.
  0     1     Reserved
  1     0     Clear OC0 on compare match, set OC0 at BOTTOM,(non-inverting mode)
  1     1     Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)
```
* Waveform Generation Mode- Bit 6, 3

In this example I have used Fast PWM mode to generate the PWM wave. To enable this mode set the WGM01 and WGM00 bits in the TCCR0 as given below.
```
Mode    WGM01      WGM00    Timer/Counter Mode of Operation
  0       0          0          Normal
  1       0          1          PWM, Phase Correct
  2       1          0          CTC
  3       1          1          Fast PWM
```
* In addition to above mentioned bits, Clock Select bits must also be configured.

## Interfacing a 16*2 LCD display through I2C
In order to interface the 16*2 LCD display through I2C, what is called `I2C interface board module`(shown below) must be attached to the LCD. After that communication can be done between the LCD and the ATMEGA32A microcontroller through the SCL and SDA pins. Additional information is available in the comments of the code.

![i2c interface module](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Figures/i2c.jpg)

To use the functions in the code I2C libraries must be added to the project. This can simply be done as follows.

1. First place the `i2c_lcd.c` , `i2c_lcd.h` , `i2cmaster.h` , `twimaster.c` files in the same directory where the `main.c` file of your project is located.
2. Then right click on the `GccApplication1` in the `solution explorer` of the Atmel Studio window and click on `Add`.
3. Next select `Existing Item...` and locate the above mentioned files and click `Add`.
4. That's it!

![guide](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Figures/guide.png)


# *References*

- As a beginner in the embedded field, the best way to learn about the controller is by creating code for each peripheral inside it. In simple words start understanding and writing code for GPIOs, ADC, PWM, Timers, Interrupts, UART, SPI, I2C, etc. [Click here to start learning step by step](https://www.electronicwings.com/avr-atmega/inside).
- With this, you can start interfacing Sensors and Modules. You can find over 40 sensors/ Modules interfacing guides with ATmega controller here. [Click Here for Interface guides of over 40 Sensors, Modules](https://www.electronicwings.com/avr-atmega/interfaces)

