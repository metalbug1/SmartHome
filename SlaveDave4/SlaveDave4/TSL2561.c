#include <DAVE.h>
#include <math.h>
#include "TSL2561.h"

float fLightIntensity;

static void TSL_Enable()
{
	uint8_t sensorEnabled;

	sensorEnabled = TSL_ReadRegister(TSL_CONTROL);
	if (TSL_ENABLE != sensorEnabled)
	{
		TSL_WriteRegister(TSL_CONTROL, TSL_ENABLE);
	}
}

static void TSL_Disable()
{
	uint8_t sensorEnabled;

	sensorEnabled = TSL_ReadRegister(TSL_CONTROL);
	if (TSL_DISABLE != sensorEnabled)
	{
		TSL_WriteRegister(TSL_CONTROL, TSL_DISABLE);
	}
}

void TimerHandlerTSL2561()
{
	TIMER_ClearEvent(&Timer_TSL_2561);
	fLightIntensity = TSL_ReadLightIntensity();
	TSL_Disable();
	TIMER_Stop(&Timer_TSL_2561);
}


uint8_t TSL_ReadRegister(TSL_RegisterAddressType registerAddress)
{
	uint8_t rcvData;
	uint8_t dataToSend;

	dataToSend = (TSL_CMD_RW_WORD | registerAddress);

	I2C_MASTER_Transmit(&I2C_TSL_2561, true, TSL2561_ADDRESS, &dataToSend, 1U, true);
	I2C_MASTER_Receive(&I2C_TSL_2561, true, TSL2561_ADDRESS, &rcvData, 1, true, true);

	return rcvData;
}
void TSL_WriteRegister(TSL_RegisterAddressType registerAddress, uint8_t data)
{
	uint8_t dataToSend[2U];

	dataToSend[0] = (TSL_CMD_RW_WORD | registerAddress);
	dataToSend[1] = data;

	I2C_MASTER_Transmit(&I2C_TSL_2561, true, TSL2561_ADDRESS, dataToSend, 2U, true);
}

float TSL_ReadLightIntensity()
{
	uint8_t adc0Low = 0;
	uint8_t adc0High = 0;
	uint8_t adc1Low = 0;
	uint8_t adc1High = 0;
	uint16_t adc0;
	uint16_t adc1;
	float adcRatio;
	float lightIntensity;
	uint8_t sensorEnabled;

	sensorEnabled = TSL_ReadRegister(TSL_CONTROL);
	if (TSL_DISABLE == sensorEnabled)
	{
		return fLightIntensity;
	}

	adc0Low = TSL_ReadRegister(TSL_DATA0LOW);
	adc0High = TSL_ReadRegister(TSL_DATA0HIGH);
	adc0 = (adc0High << 8U) + adc0Low;
	adc1Low = TSL_ReadRegister(TSL_DATA1LOW);
	adc1High = TSL_ReadRegister(TSL_DATA1HIGH);
	adc1 = (adc1High << 8U) + adc1Low;

	if (adc0 != 0)
	{
		adcRatio = (adc1/adc0);
	}
	else
	{
		adcRatio = 0;
	}

	do
	{
		if (adcRatio > 1.3)
		{
			lightIntensity = 0;
			break;
		}
		if (adcRatio > 0.8)
		{
			lightIntensity = 0.00146 * (float)adc0 - 0.00112 * (float)adc1;
			break;
		}
		if (adcRatio > 0.61)
		{
			lightIntensity =  0.0128  * (float)adc0 - 0.0153  * (float)adc1;
			break;
		}
		if (adcRatio > 0.5)
		{
			lightIntensity =  0.0224  * (float)adc0 - 0.031 * (float)adc1;
			break;
		}
		lightIntensity = 0.0304 * (float)adc0 -  0.062 * (float)adc0 * (pow(adcRatio, 1.4));

	}while(0);

	return lightIntensity;
}

void TSL_Start()
{
	TSL_Enable();
	TIMER_Start(&Timer_TSL_2561);
}
