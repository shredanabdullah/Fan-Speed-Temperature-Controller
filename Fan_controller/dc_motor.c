/*
 * dc_motor.c
 *
 *  Created on: Oct 14, 2023
 *      Author: shredan abdullah
 */

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"


/*Description:
➢ The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
➢ Send the required duty cycle to the PWM driver based on the
required speed value.
*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed){
	    uint8 dutyCycle = 0;

		/* Set the out put of the two motor pins to change its rotation direction depending on the input */

		  switch(state)
		  {
		  case stop :
			  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_FIRST_PIN_ID , LOGIC_LOW);
			  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_SECOND_PIN_ID , LOGIC_LOW);
			  break;
		  case CW :
		  	  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_FIRST_PIN_ID , LOGIC_HIGH);
		  	  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_SECOND_PIN_ID , LOGIC_LOW);
		  	  break;
		  case A_CW :
		  	  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_FIRST_PIN_ID , LOGIC_LOW);
		  	  GPIO_writePin(DC_PORT_ID ,DC_MOTOR_SECOND_PIN_ID , LOGIC_HIGH);
		  	  break;
		  }
		/* The equation to transform the speed into duty cycle and send to the timer driver */
//		switch(speed)
//		  {
//		  case 0 :
//			  PWM_Timer0_Start(0);
//			  break;
//		 /* 25% duty cycle */
//		  case 25 :
//			  PWM_Timer0_Start(64);
//			  break;
//		 /* 50% duty cycle */
//		  case 50 :
//			  PWM_Timer0_Start(128);
//			  break;
//		 /* 75% duty cycle */
//		  case 75 :
//			  PWM_Timer0_Start(192);
//			  break;
//		/* 100% duty cycle */
//		  case 100 :
//			  PWM_Timer0_Start(255);
//			  break;
//		  }
			dutyCycle = (uint8)(((float32)speed / DC_MAX_SPEED) * 100);
			PWM_Timer0_Start(dutyCycle);
}


/*Description
➢ The Function responsible for setup the direction for the two
motor pins through the GPIO driver.
➢ Stop at the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor_Init(void){

	/* Set the two motor pins as output pins */
	 GPIO_setupPinDirection(DC_PORT_ID, DC_MOTOR_FIRST_PIN_ID,  PIN_OUTPUT);
	 GPIO_setupPinDirection(DC_PORT_ID,  DC_MOTOR_SECOND_PIN_ID,  PIN_OUTPUT);

	DcMotor_Rotate(stop,0);
}
