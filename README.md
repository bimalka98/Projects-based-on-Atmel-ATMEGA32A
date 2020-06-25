# Projects-based-on-Atmel-ATMEGA32A
This repository includes projects based on Atmel ATMEGA32A microcontroller.
# Pinout of the Atmel ATMEGA32A microcontroller
![pinout atmega](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Figures/Pinout.PNG)
## Port A

* Analog input to the Analog to Digital(A/D) converter
* 8-bit bidirectional input/output(I/O) port, if it is not used as analog input to A/D converter.

## Port B, Port C, Port D

* 8-bit bidirectional input/output(I/O) ports

# Configuration of pins

## Data Direction of a pin

* If set to logic 1 --> Output
* If set to logic 0 --> Input

In general,
```
n = {A, B, C, D}
DDRn | = 0bxxxxxxxx;
A register has 8 bits therefore every bit must be precisely configured. x can be either 0 or 1.

Else this can be done as follows

n = {A, B, C, D} and i = {0, 1, 2, 3, 4, 5, 6, 7}
DDRn  | = (x << PINni);
```
Imagine we  need to configure the PINC0 to be an output pin and every other pin to be an input pin in that port, it can be done as follows.

```
DDRC | = 0b00000001;
or
DDRC | = (1 << PINC0);
```
## Logical state of a pin

* If set to logic 1 --> HIGH
* If set to logic 0 --> LOW

In general,
```
n = {A, B, C, D}, i = {0,1,2,3,4,5,6,7}

PORTn | = (1 << PINni);
This PORTn register also contains 8 bits therefore every bit must be precisely configured if the binary format is used.
```

Imagine we  need to make PINC0 HIGH. This can be done as follows. To make it LOW, code in the next line can be used.
```
PORTC | = (1 << PINC0);
PORTC & = ~(1 << PINC0);
```
# PROJECTS
## Blink an LED
![Wiring of blink an led project](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Blink_an_LED/Figures/wiring.jpg)

## Knight Rider Effect
![Wiring of Knight Rider Effect project](https://github.com/bimalka98/Projects-based-on-Atmel-ATMEGA32A/blob/master/Knight_Rider_effect/kre.jpg)

## Time delaying without using built-in functions

### Timers in ATMEGA32A

ATMEGA32A has three timers.
* Timer 0  08-bit timer TCNT0, OCR0, TCCR0
* Timer 1  16-bit timer TCNT1, OCR1, TCCR1
* Timer 2  08-bit timer TCNT2, OCR2, TCCR2

Each timer in ATMEGA32A is mainly associated with three different registers. Namely `TCNTn`(Timer Counter register) which counts the clock ticks, `OCRn`(Output Compare register) which is used to store some value to be compared with the TCNTn and finally the `TCCRn`(Timer Counter control register) which is used to configure the operation mode of the timer. The first three bits(2:0) in the TCCRn register are used to select the clock source and called `Clock Select(CS)` bits.
```
TCCR0 Register

Bit           7     6     5      4    3     2     1   0
TCCR0         FOC0 WGM00 COM01 COM00 WGM01 CS02 CS01 CS00
Read/Write    W     R/W   R/W   R/W   R/W  R/W  R/W  R/W
Initial Value 0     0     0      0    0     0    0    0
```
Configuration of CS bits are done as follows.
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
## Change light intensity of an LED using Pulse Width Modulation(PWM)

Simply PWM is a way of getting an analog output using a digital signal.
