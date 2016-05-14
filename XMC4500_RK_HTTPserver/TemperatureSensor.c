/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/

#include "TemperatureSensor.h"


ADC001_ResultHandleType AdcConversionResult;


void TemperatureSensorInit()
{
    ADC001_GenerateLoadEvent(&ADC001_Handle0);
}

uint16_t GetTemperature()
{
	float fVoltage = 0;
	float fTempSensorResistance = 0;
	float fPreciseTemperature = 0;
	uint16_t u16AdcResult;
	uint16_t u16Temperature;

	u16AdcResult = AdcConversionResult.Result;
	fVoltage = (u16AdcResult * ADC_VCC_VOLTAGE_MILIVOLTS) / ADC_MAX_VALUE;
	fTempSensorResistance = fVoltage * 1000/(ADC_VCC_VOLTAGE_MILIVOLTS - fVoltage);
	fPreciseTemperature = (uint8_t)((0.1272 * fTempSensorResistance - 103.1) * 10);

	if (((uint16_t)fPreciseTemperature % 10) < 5)
	{
		u16Temperature = (uint16_t)(fPreciseTemperature/10);
	}
	else
	{
		u16Temperature = (uint16_t)(fPreciseTemperature/10) + 1;
	}

	return u16Temperature;
}


void ADC_ConversionComplete()
{
	ADC001_GetResult(&ADC001_Handle0, &AdcConversionResult);
}
