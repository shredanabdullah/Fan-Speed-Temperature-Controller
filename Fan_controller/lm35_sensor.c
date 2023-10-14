/*
 * lm35_sensor.c
 *
 *  Created on: Oct 7, 2023
 *      Author: shredan abdullah
 */
#include "adc.h"
#include "lm35_sensor.h"

uint8 LM35_getTemperature(void){
	    uint8 temp_value = 0;

		uint16 adc_value = 0;

	    /* Read ADC channel where the temperature sensor is connected */
	    adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

		/* Calculate the temperature from the ADC value*/
		temp_value = (uint8)(((uint32)adc_value * SENSOR_MAX_TEMPERATURE * ADC_REF_VOLTAGE) / (ADC_MAXIMUM_VALUE * SENSOR_MAX_TEMPERATURE_READ));
		//temp_value = (uint8)(((uint32)g_ADC_RETURN_VALU*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLTAGE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_TEMPERATURE_READ));

		return temp_value;
	//return uint8 temperature = (uint8)( ( (uint32)ADC_readChannel(SENSOR_CHANNEL_ID)* MAX_TEMPERATURE * REF_ADC_VOLTAGE) / (MAX_TEMPERATURE_READ * ADC_MAXIMUM_VALUE) );
}
