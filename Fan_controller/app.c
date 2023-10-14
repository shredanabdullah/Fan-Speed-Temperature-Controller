/*
 * app.c
 *
 *  Created on: Oct 14, 2023
 *      Author: shredan abdullah
 */

#include "std_types.h"
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_sensor.h"
#include "adc.h"


int main(void){
	/*initialization*/
	uint8 temperature = 0;

	/* Initialize LCD and DC motor modules */
	 LCD_init();
	 DcMotor_Init();

	/* ADC initialization Vref and prescaler */
	 ADC_ConfigType s_configuration = {Internal_2_56V_Voltage_Reference, FCPU_8};
	 ADC_init (& s_configuration);

	 /* Display the fixed data on LCD */
	 	LCD_moveCursor (1,3);
	 	LCD_displayString ("FAN IS ");
	 	LCD_moveCursor (2,2);
	 	LCD_displayString ("TEMP =");
	 	/*
	 	a. If the temperature is less than 30C turn off the fan.
	 	b. If the temperature is greater than or equal 30C turn on the fan with 25% of its
	 	maximum speed.
	 	c. If the temperature is greater than or equal 60C turn on the fan with 50% of its
	 	maximum speed.
	 	d. If the temperature is greater than or equal 90C turn on the fan with 75% of its
	 	maximum speed.
	 	e. If the temperature is greater than or equal 120C turn on the fan with 100% of its
	 	maximum speed.*/

	/*super loop*/
	 	while(1){

	 		temperature = LM35_getTemperature();
	 		if(temperature < 30 )
	 				{
	 					DcMotor_Rotate(stop , DC_MIN_SPEED);
	 					LCD_moveCursor (1,10);
	 					LCD_displayString ("OFF");
	 					LCD_moveCursor(2,9);
	 					LCD_intgerToString (temperature);
	 					LCD_displayCharacter(' ');
	 					LCD_displayStringRowColumn(2, 13, "C");
	 				}
	 				else if(temperature >= 30 && temperature <60 )
	 				{
	 					DcMotor_Rotate(CW , 25);
	 					LCD_moveCursor (1,10);
	 					LCD_displayString ("ON");
	 					LCD_moveCursor(2,9);
	 					LCD_intgerToString (temperature);
	 					LCD_displayCharacter(' ');
	 					LCD_displayStringRowColumn(2, 13, "C");
	 				}
	 				else if(temperature >=60 && temperature <90 )
	 				{
	 					DcMotor_Rotate(CW , 50);
	 					LCD_moveCursor (1,10);
	 					LCD_displayString ("ON");
	 					LCD_moveCursor(2,9);
	 					LCD_intgerToString (temperature);
	 					LCD_displayCharacter(' ');
	 					LCD_displayStringRowColumn(2, 13, "C");
	 				}
	 				else if(temperature >=90 && temperature <120 )
	 				{
	 					DcMotor_Rotate(CW , 75);
	 					LCD_moveCursor (1,10);
	 					LCD_displayString ("ON");
	 					LCD_moveCursor(2,9);
	 					LCD_intgerToString (temperature);
	 					LCD_displayCharacter(' ');
	 					LCD_displayStringRowColumn(2, 13, "C");
	 				}
	 				else if(temperature > 120 )
	 				{
	 					DcMotor_Rotate(CW , DC_MAX_SPEED);
	 					LCD_moveCursor (1,10);
	 					LCD_displayString ("ON");
	 					LCD_moveCursor (2,9);
	 					LCD_intgerToString (temperature);
	 					LCD_displayCharacter(' ');
	 					LCD_displayStringRowColumn(2, 13, "C");
	 				}
	 	}
	 return 0;
}
