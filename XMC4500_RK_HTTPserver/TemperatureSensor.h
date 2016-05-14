/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    14/05/2016    Initial version						 */
/*********************************************************************/


#ifndef _TEMPERATURESENSOR_H
#define _TEMPERATURESENSOR_H

#include <DAVE3.h>
#include "SmartHome_Types.h"
#include "DataQueue.h"

#define ADC_VCC_VOLTAGE_MILIVOLTS (3300)
#define ADC_MAX_VALUE 		 	  (4096)


void TemperatureSensorInit();

#endif
