/*
 * lm35_sensor.h
 *
 *  Created on: Oct 7, 2023
 *      Author: shredan abdullah
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"

#define SENSOR_CHANNEL_ID     2

#define SENSOR_MAX_TEMPERATURE_READ  1.5
#define SENSOR_MAX_TEMPERATURE       150
#define SENSOR_RESOLUTION            10/*the sensitivity of lm35 is 10mv per celsius degree if it's 27 degree the output is 270 mv*/

uint8 LM35_getTemperature(void);

#endif /* LM35_SENSOR_H_ */
