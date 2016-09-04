#include <stdint.h>
#include "DHT22Pin.h"
#include "DHT22Timer.h"
#include "dht.h"

LDD_TDeviceData *DhtPinHandler = NULL;

DHT_State eDhtState = DHT_IDLE;
uint8_t u8NumberOfRecvBits = 0;
uint8_t u8NumberOfTimerInterrupts = 0;
uint16_t u16Humidity = 0;
uint16_t u16Temperature = 0;
uint16_t u16Aux = 0;

void DHT22Timer_10usEvent()
{
	u8NumberOfTimerInterrupts++;
	switch (eDhtState)
	{
		case DHT_HOST_PULL_DOWN:
		{
			if (u8NumberOfTimerInterrupts >= 100)
			{
				u8NumberOfTimerInterrupts = 0;
				DHT22Pin_SetVal(&DhtPinHandler);
				eDhtState = DHT_HOST_PULL_UP;
				DHT22Pin_SetInput(&DhtPinHandler);
			}
		} break;

		case DHT_HOST_PULL_UP:
		{
			if (DHT22Pin_GetVal(&DhtPinHandler) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_DOWN;
			}
		} break;

		case DHT_SENSOR_PULL_DOWN:
		{
			if (DHT22Pin_GetVal(&DhtPinHandler) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_UP;
			}
		} break;

		case DHT_SENSOR_PULL_UP:
		{
			if (DHT22Pin_GetVal(&DhtPinHandler) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PREPARE_SENDING;
			}
		} break;

		case DHT_SENSOR_PREPARE_SENDING:
		{
			if (DHT22Pin_GetVal(&DhtPinHandler) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_READ_BIT;
			}
		} break;

		case DHT_SENSOR_READ_BIT:
		{
			if (DHT22Pin_GetVal(&DhtPinHandler) == 0)
			{
				u8NumberOfRecvBits++;
				u16Aux <<= 1;
				if (u8NumberOfTimerInterrupts > 4)
				{
					u16Aux |= 1;
				}
				if (u8NumberOfRecvBits == 16)
				{
					u16Humidity = u16Aux;
					u16Aux = 0;
				}
				if (u8NumberOfRecvBits == 32)
				{
					u16Temperature = u16Aux;
					u16Aux = 0;
				}
				if (u8NumberOfRecvBits == 40)
				{
					eDhtState = DHT_FINISHED;
				}
				else
				{
					u8NumberOfTimerInterrupts = 0;
					eDhtState = DHT_SENSOR_PREPARE_SENDING;
				}
			}
		} break;

		case DHT_FINISHED:
		{
			DHT22Timer_Disable();
		} break;

		default:
		{

		}break;
	}
}

void DHT_Read()
{
	if (NULL == DhtPinHandler)
	{
		DhtPinHandler = DHT22Pin_Init((LDD_TUserData *)NULL);
	}
	DHT22Pin_SetOutput(&DhtPinHandler);
	DHT22Pin_ClrVal(&DhtPinHandler);
	eDhtState = DHT_HOST_PULL_DOWN;
	DHT22Timer_Enable();
}

