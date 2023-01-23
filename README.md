
# Simple AC phase control

Compact AC Phase contorol with zero corssing circuit using [ATtiny13u](https://ww1.microchip.com/downloads/en/devicedoc/doc2535.pdf).
The scope of this project is build an efficient, scalable and simple to-solder dimming circuit, for resistive ac loads like heaters, also it can work with small motors.
It can be rewritten to be used with others AVR 8-Bit Atmel Microcontrollers. Also, the power stage can be replaced for your amperage needs  


## Advantages 
Comercial AC Dimmers aree commonly built with a power stage and a control circuit wich are commonly
based on a rotary potentiomer and resistor/s, this approach is both inaccurate and unreliable, because it stop working pretty soon and also creates a lot of [harmonics](https://www.electronics-tutorials.ws/accircuits/harmonics.html) that impacts in Power Factor (PF) and Total Harmonic Distortion (THD).

The control circuit in this design, uses timmers and _zero crossing circuit_ that reduce the impact on PF and THD.

## Principle of function 

### Zero crossing circuit 
- The zero crossing circuit make a pulse every zero-voltage value, thas is a frecuency of (60*2)= 120 Hz. 

<p align="center">
	<img alt="Zero crossing circuit" width="430" src="https://user-images.githubusercontent.com/22565959/213883584-a254b72b-0fbb-4e92-a54c-57aa0edd1ea1.png">
	<img alt="Zero crossing circuit" width="300" src="https://user-images.githubusercontent.com/22565959/213883593-dad12f7b-1464-446e-ac99-6e66b3f474ec.png">
</p>

### Control circuit
This project was written using the peripherals: ADC, interruptions and timmers of Attiny13u, so there is not a polling routine. 
The general idea of what happens inside the code is below:

- **ADC** channel is constanly sensing the value of the rotary potentiometer and map it to a _pulse width_ value in the **timmer**. This value can be in range of 0-8.33ms, wish represent the period of the zero crossing values.
- The zero crossing circuit trigers an input corresponding to an **interrupt** that enables a **square waveform** wich inits in the zero value and with a pulse width corresponding to the value maped from the ADC channel. 
- The power stage switch the load, synchronized with the **square waveform**, on and off. 

<p align="center">
	<img alt="Control signals" width="700" src="https://user-images.githubusercontent.com/22565959/213885312-7970b64f-5aaa-4afe-a145-01eb5e3af3bd.png">
</p>

## Breadboard
<p align="center">
	<img alt="Breadboard" width="700" src="https://user-images.githubusercontent.com/22565959/213962371-aab461fb-0b41-4ed1-b052-d9c24785229b.png">
</p>
