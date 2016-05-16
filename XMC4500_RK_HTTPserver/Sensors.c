/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/

#include "Sensors.h"

ADC001_ResultHandleType AdcConversionResult;

uint16_t TemperatureAdcConversion;
uint16_t LightAdcConversion;
uint16_t HumidityAdcConversion;

uint8_t au8HumidityTable[] = {20, 30, 40, 50, 60, 70, 80, 90, 95};

float afHumidityResistance20DegreesTable[] = {8200, 2800, 689, 263.5, 67.25, 28, 8.2, 5, 3.6};
float afHumidityResistance25DegreesTable[] = {7430, 1645, 450, 100, 50, 16.5, 7.2, 4.27, 2.8};
float afHumidityResistance30DegreesTable[] = {6400, 967, 460, 85.25, 39.45, 9.65, 6.2, 3.45, 2};

void UpdateSensorInformation()
{
	GetTemperature();
	GetLight();
	GetHumidity();
}


/* Uses the data received in the ADC Conversion Complete interrupt to get a temperature
 * value in Celsius degrees. The function will round the temperature to a uint16 value.
 */
void GetTemperature()
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
	roomInformation[ROOM_INDEX(LIVING)].u8Temperature[0] = (uint8_t)u16Temperature;
	roomInformation[ROOM_INDEX(LIVING)].u8Temperature[1] = (uint8_t)((uint16_t)fPreciseTemperature % 10);
}

void GetLight()
{
	roomInformation[ROOM_INDEX(LIVING)].u8Light[0] = (uint8_t)(LightAdcConversion/21);
	roomInformation[ROOM_INDEX(LIVING)].u8Light[1] = (uint8_t)((LightAdcConversion/21) % 10);
}

void GetHumidity()
{
	float fVoltage = 0;
	float fPreciseHumidity = 0;
	float fHumiditySensorResistance = 0;

	/* The input voltage will result in a maximum value for the ADC channel, so:
	 * HUMIDITY_ADC_VCC_VOLTAGE_MILIVOLTS ......... HUMIDITY_ADC_MAX_VALUE
	 * fVoltage ..................................... HumidityAdcConversion
	 *
	 * fVoltage = (HumidityAdcConversion * HUMIDITY_ADC_VCC_VOLTAGE_MILIVOLTS) / HUMIDITY_ADC_MAX_VALUE
	 * In our case: fVoltage = (HumidityAdcConversion * 3300 mV) / 4096
	 */
	fVoltage = (HumidityAdcConversion * HUMIDITY_ADC_VCC_VOLTAGE_MILIVOLTS) / HUMIDITY_ADC_MAX_VALUE;

	/* Knowing the resistance divisor formula and members we can calculate the temperature sensor
	 * resistance:
	 * Vout = Vin * Rsensor / (R + Rsensor)
	 * Rsensor = Vout * R / (Vin - Vout)
	 * fVoltage = HUMIDITY_RESISTOR_VALUE_OHM * fHumiditySensorResistance / (HUMIDITY_RESISTOR_VALUE_OHM + fHumiditySensorResistance)
	 */
	fHumiditySensorResistance = fVoltage * HUMIDITY_RESISTOR_VALUE_OHM/(HUMIDITY_ADC_VCC_VOLTAGE_MILIVOLTS - fVoltage);

	roomInformation[ROOM_INDEX(LIVING)].u8Humidity[0] = HumidityAdcConversion/21;
	roomInformation[ROOM_INDEX(LIVING)].u8Humidity[1] = 0;
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
	if (AdcConversionResult.ChannelNo == ADC_HUMIDSENSOR_CHANNEL)
	{
		HumidityAdcConversion = AdcConversionResult.Result;
	}
	if (AdcConversionResult.ChannelNo == ADC_LIGHTSENSOR_CHANNEL)
	{
		LightAdcConversion = AdcConversionResult.Result;
	}
}
