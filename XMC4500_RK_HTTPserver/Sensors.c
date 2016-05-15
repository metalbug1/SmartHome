/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/

#include "Sensors.h"


ADC001_ResultHandleType AdcConversionResult;

uint16_t TemperatureAdcConversion;
uint16_t LightAdcConversion;

/* Uses the data received in the ADC Conversion Complete interrupt to get a temperature
 * value in Celsius degrees. The function will round the temperature to a uint16 value.
 */
void GetTemperature(uint8_t au8Temperature[])
{
	float fVoltage = 0;
	float fTempSensorResistance = 0;
	float fPreciseTemperature = 0;
	uint16_t u16Temperature;

	/* The input voltage will result in a maximum value for the ADC channel, so:
	 * TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS ......... TEMPSENSOR_ADC_MAX_VALUE
	 * fVoltage ..................................... u16AdcResult
	 *
	 * fVoltage = (u16AdcResult * TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS) / TEMPSENSOR_ADC_MAX_VALUE
	 * In our case: fVoltage = (u16AdcResult * 3300 mV) / 4096
	 */
	fVoltage = (TemperatureAdcConversion * TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS) / TEMPSENSOR_ADC_MAX_VALUE;

	/* Knowing the resistance divisor formula and members we can calculate the temperature sensor
	 * resistance:
	 * Vout = Vin * Rsensor / (R + Rsensor)
	 * Rsensor = Vout * R / (Vin - Vout)
	 * fVoltage = TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS * fTempSensorResistance / (TEMPSENSOR_RESISTOR_VALUE_OHM + fTempSensorResistance)
	 */
	fTempSensorResistance = fVoltage * TEMPSENSOR_RESISTOR_VALUE_OHM/(TEMPSENSOR_ADC_VCC_VOLTAGE_MILIVOLTS - fVoltage);

	/* Using the data in the sensor data sheet the following formula was found for the temperature
	 * based on the temperature sensor resistance
	 */
	fPreciseTemperature = (uint8_t)((0.1272 * fTempSensorResistance - 103.1) * 10);


	/* Round the temperature value to the closest integer */
	if (((uint16_t)fPreciseTemperature % 10) < 5)
	{
		u16Temperature = (uint16_t)(fPreciseTemperature/10);
	}
	else
	{
		u16Temperature = (uint16_t)(fPreciseTemperature/10) + 1;
	}
	au8Temperature[0] = (uint8_t)u16Temperature;
	au8Temperature[1] = (uint8_t)((uint16_t)fPreciseTemperature % 10);
}

void GetLight(uint8_t au8Light[])
{
	au8Light[0] = LightAdcConversion/21;
	au8Light[1] = 0;

}




/* ISR for the ADC Conversion Complete */
void ADC_ConversionComplete()
{
	/* The result will be saved in the AdcConversionResult structure */
	ADC001_GetResult(&ADC001_Handle0, &AdcConversionResult);

	if (AdcConversionResult.ChannelNo == ADC_TEMPSENSOR_CHANNEL)
	{
		TemperatureAdcConversion = AdcConversionResult.Result;
	}
	if (AdcConversionResult.ChannelNo == ADC_LIGHTSENSOR_CHANNEL)
	{
		LightAdcConversion = AdcConversionResult.Result;
	}
}
