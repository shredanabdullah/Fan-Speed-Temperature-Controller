/*
 * pwm.c
 *
 *  Created on: Oct 14, 2023
 *      Author: shredan abdullah
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "pwm.h"
#include "gpio.h"

/*
 Description:
➢ The function responsible for trigger the Timer0 with the PWM Mode.
➢ Setup the PWM mode with Non-Inverting.---
➢ Setup the prescaler with F_CPU/8.---
➢ Setup the compare value based on the required input duty cycle--
➢ Setup the direction for OC0 as output pin through the GPIO driver.--
➢ The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
*/
void PWM_Timer0_Start(uint8 duty_cycle){

	TCNT0 = 0; // Set Timer Initial Value to 6 because tick time =250 and max ocr0 =256
	//OCR0  = duty_cycle; // Set Compare Value
	 OCR0  = 255*((float32)duty_cycle/100); // Set Compare Value
	//OCR0 = ceil ((duty_cycle / 100.0) * 255);    /* Set compare value */
	GPIO_setupPinDirection(PORTB_ID, PWM_PIN_ID, PIN_OUTPUT );
	//DDRB  = DDRB | (1<<PB3); // Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC

	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

//ISR(TIMER1_OVF_vect){
//	TCNT0 = 6;
//}
