/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    14/05/2016    Initial version						 */
/*********************************************************************/


#ifndef _SENSORS_H
#define _SENSORS_H

#include <DAVE3.h>
#include "SmartHome_Types.h"
#include "DataQueue.h"

/* The VCC value that is used for the temperature sensor circuit */
#define TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS 			(3300)
/* The maximum value of the ADC based on the resolution used
 * For 12 bits resolution the maximum value is 4096
 */
#define TEMPSENSOR_ADC_MAX_VALUE 		 	  			(4096)
/* The resistor used for the resistor divisor of the temperature sensor */
#define TEMPSENSOR_RESISTOR_VALUE_OHM  					(1000)

uint16_t GetTemperature();

#endif
