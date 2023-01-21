
# Simple AC phase control

Compact AC Phase contorol with zero corssing circuit using [ATtiny13u]{https://ww1.microchip.com/downloads/en/devicedoc/doc2535.pdf].
The scope of this project is build an efficient, scalable and simple to-solder dimming circuit, for resistive ac loads like heaters, also it can work with small motors.
It can be rewritten to be used with others AVR 8-Bit Atmel Microcontrollers. Also, the power stage can be replaced for your amperage needs  


## Advantages 
Comercial AC Dimmers aree commonly built with a power stage and a control circuit wich are commonly
based on a rotary potentiomer and resistor/s, this approach is both inaccurate and unreliable, because it stop working pretty soon and also creates a lot of [harmonics](https://www.electronics-tutorials.ws/accircuits/harmonics.html) that impacts in Power Factor (PF) and Total Harmonic Distortion (THD).

The control circuit in this design, uses timmers and _zero crossing circuit_ that reduce the impact on PF and THD.

## Principle of function 

### Control circuit
This project was written using the peripherals: ADC, interruptions and timmers of Attiny13u, so there is no a big routine . 
The general idea of what happens inside the code is below:
- The zero crossing circuit make a pulse every zero-voltage value, thas is a frecuency of 60 Hz. 
- **ADC** channel is constanly sensing the value of the rotary potentiometer and map it to a _pulse width_ value in the **timmer**. This value can be in range of 0-8.33ms, wish represent the period of the zero crossing values.
- The zero crossing circuit trigers an interrupt that enables a square waveform wich inits in the zero value and with a pulse width corresponding o. 
- 

## Circuit

## 
