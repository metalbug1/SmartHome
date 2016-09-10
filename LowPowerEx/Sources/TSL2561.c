#include <stdint.h>
#include <math.h>
#include "TSL2561.h"
//#include "TSL2561I2C.h"
#include "TSL2561Timer.h"
#include "I2C_PDD.h"
#include "i2c.h"

TSL_StateType TslSensorState = TSL_IDLE;
float fLightIntensity;

LDD_TDeviceData *TSL2561I2CHandler = NULL;
volatile bool DataReceivedFlg = FALSE;
volatile bool DataTransmittedFlg = FALSE;
volatile bool sensorRead = 0;

void TSL2561I2C_DataReceived()
{
	DataReceivedFlg = TRUE;
}
void TSL2561I2C_DataSent()
{
	DataTransmittedFlg = TRUE;
}

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

void TSL2561Timer_500msEvent()
{
	if (0 == sensorRead)
	{
		sensorRead = 1;
		fLightIntensity = TSL_ReadLightIntensity();
		//TSL_Disable();
		TSL2561Timer_DisableEvent();
		TSL2561Timer_Disable();
		TslSensorState = TSL_FINISHED;
	}
}


uint8_t TSL_ReadRegister(TSL_RegisterAddressType registerAddress)
{
	return I2CReadRegister(TSL_CMD_RW_WORD | registerAddress);
}
void TSL_WriteRegister(TSL_RegisterAddressType registerAddress, uint8_t data)
{
	I2CWriteRegister((TSL_CMD_RW_WORD | registerAddress), data);
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
	TslSensorState = TSL_IDLE;
	sensorRead = 0;
	TSL_Enable();
	TSL2561Timer_Enable();
	TSL2561Timer_EnableEvent();
}
