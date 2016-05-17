/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    17/05/2016    Initial version						 */
/*********************************************************************/

#include <DAVE3.h>
#include "Sensors.h"


#define ADC_TEMPSENSOR_CHANNEL							(1)
#define ADC_HUMIDSENSOR_CHANNEL							(2)
#define ADC_LIGHTSENSOR_CHANNEL							(3)

extern uint16_t TemperatureAdcConversion;
extern uint16_t LightAdcConversion;
extern uint16_t HumidityAdcConversion;

/* ISR for the ADC Conversion Complete */
void ADC_ConversionComplete()
{
	ADC001_ResultHandleType AdcConversionResult;

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
