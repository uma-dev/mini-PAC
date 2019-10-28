#include <avr/io.h>
#include <avr/interrupt.h>

#define TRIAC PB3                                //TRIAC gate
#define INTERRUPT_PIN PB1                        //Interrupt pin
#define PULSE 1                                  //trigger pulse width (counts)

void pins_init(){
  DDRB &= ~(1 << INTERRUPT_PIN);                 //Two lines to declare pin as input pull-up
  PORTB |= (1 << INTERRUPT_PIN);
  DDRB |= (1 << TRIAC);                          //Pin 2 (PB3) as output
}

void timer_init(){
  TCCR0A = 0x00;                                 //Normal mode by default
  TCCR0B = 0x00;                                 //Normal mode by default, timer disabled
  
  TIMSK0 |= (1<<TOIE0);                          //Enable the timer overflow
  TIMSK0 |= (1<<OCIE0A);                         //Enable comparator A
  OCR0A = 100;                                   //initialize the comparator to 100 (default value)  
}

void  interrupt_init(){                          //zero cross detect   
  //MCUCR |= (1 << ISC00)|(1 << ISC01);          // turns on interrupt for INT0 (rising edge)
  MCUCR |= (1 << ISC01);                         // turns on interrupt for INT0 (falling edge)
  GIMSK |= (1 << INT0);                          // allow external interrupts
  SREG |= (1 <<  7);                             // global interrupt enable
}

void adc_init(){
  ADMUX |= (1 << ADLAR);                         //Left Adjust the ADCH and ADCL registers (8 bit resolution)
  ADMUX |= (1 << MUX1);                          //Use the channel 2 of the ADC (pin 3)
  ADCSRA = 0b10000110;                           //ADC clock runs 64 times (110) slower than system clock  
}

void setup(){
  pins_init();                                   //Work with pins
  timer_init();                                  //Work with the timer 
  interrupt_init();                              //Set up zero crossing interrupt
  adc_init();                                    //Configure ADC
}  

//Interrupt Service Routines

ISR(INT0_vect){
  TCCR0B |= (1 << CS02);                         //start timer with divide by 256 input
  TCNT0 = 0;                                     //reset timer counter - count from zero  
}

ISR(TIM0_COMPA_vect){                            //comparator match
  PORTB |= (1 << TRIAC);                         //Write a '1'  to triac
  TCNT0 = 256-PULSE;                             //trigger pulse width
}

ISR(TIM0_OVF_vect) {                             //timer1 overflow
  PORTB &= ~(1 << TRIAC);                        //Write a '0'  
  TCCR0B = 0x00;                                 //disable timer stopd unintended triggers
}

void loop(){                                     // sample code to exercise the circuit
  ADCSRA |= (1 << ADSC);                         //start conversion
  if(ADCH >=30)  OCR0A = (ADCH+246)%256;         //set the compare register brightness desired.     (210 for use of diac and 180/190 without it)
  delay(100);                             
}
