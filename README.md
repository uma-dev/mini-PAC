
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
	<img alt="Zero crossing circuit" width="430" src="https://user-images.githubusercontent.com/22565959/213965436-39252004-31a5-446c-9ea9-95e6fbf97086.png">
	<img alt="Zero crossing circuit" width="300" src="https://user-images.githubusercontent.com/22565959/213883593-dad12f7b-1464-446e-ac99-6e66b3f474ec.png">
</p>

### Control circuit
This project was written using the peripherals: ADC, interruptions and timmers of Attiny13u, so there is not a polling routine. 
The general idea of what happens inside the code is below:

- **ADC** channel 2 is constanly sensing the value of the **input PB4 (rotary potentiometer)** and map it to a _pulse width_ value in the **timmer**. This value can be in range of 0-8.33ms, wish represent the period of the zero crossing values.
- The zero crossing circuit trigers an **input PB1 (interrupt)** that enables an **output PB3 (square waveform)** wich inits in the zero value and with a pulse width corresponding to the value maped from the ADC channel. 
<p align="center">
	<img alt="Attiny13 pinout" width="730" src="https://user-images.githubusercontent.com/22565959/213964056-52abe15f-8d0f-4357-b6c1-ad6b9b194a51.png">
</p>

### Power stage 

- The power stage switch the load, synchronized with the **square waveform**, on and off. 

<p align="center">
	<img alt="Power stage" width="412" src="https://user-images.githubusercontent.com/22565959/213963618-809bdb3e-eeaf-4fa9-9dda-a492a0eaf045.jpg">
	<img alt="Control signals" width="318" src="https://user-images.githubusercontent.com/22565959/213885312-7970b64f-5aaa-4afe-a145-01eb5e3af3bd.png">
</p>

## Breadboard
<p align="center">
	<img alt="Breadboard" width="710" src="https://user-images.githubusercontent.com/22565959/213962371-aab461fb-0b41-4ed1-b052-d9c24785229b.png">
</p>
<p align="center">
	<img alt="Breadboard" width="710" src="https://user-images.githubusercontent.com/22565959/213968767-fd9b4acf-b717-4068-8240-156c5fce34f3.jpg">

</p>

## Programmer
<p align="center">
	<img alt="Programmer" width="710" src="https://user-images.githubusercontent.com/22565959/218610842-4019c74e-a2bf-4b8d-b83a-72a9fb3ee51d.jpg">
</p>

## DC Motor
<p align="center">
	<img alt="DC motor" width="710" src="https://user-images.githubusercontent.com/22565959/218610623-f00be736-da76-449a-95ad-4bcd2a06a1ee.jpg">
</p>


