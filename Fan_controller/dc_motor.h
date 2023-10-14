/*
 * dc_motor.h
 *
 *  Created on: Oct 14, 2023
 *      Author: shredan abdullah
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include"std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Parameters Definitions */
#define DC_MAX_SPEED      100
#define DC_MIN_SPEED      0

/* Static Configurations */
#define DC_PORT_ID               PORTB_ID
#define DC_MOTOR_FIRST_PIN_ID    PIN0_ID
#define DC_MOTOR_SECOND_PIN_ID   PIN1_ID

/*******************************************************************************
 *                               Enumerations                                  *
 *******************************************************************************/
typedef enum{
	CW, A_CW ,stop
}DcMotor_State;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Description
➢ The Function responsible for setup the direction for the two
motor pins through the GPIO driver.
➢ Stop at the DC-Motor at the beginning through the GPIO driver.
*/
void DcMotor_Init(void);

/*Description:
➢ The function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
➢ Send the required duty cycle to the PWM driver based on the
required speed value.
*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
