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
