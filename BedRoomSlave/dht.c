#include <DAVE3.h>
#include "dht.h"

handle_t TimerId;
DHT_State eDhtState = DHT_IDLE;
uint8_t u8NumberOfRecvBits = 0;
uint8_t u8NumberOfTimerInterrupts = 0;
uint16_t u16Humidity = 0;
uint16_t u16Temperature = 0;
uint16_t u16Aux = 0;

void TimerHandlerReadSensors()
{
	u8NumberOfTimerInterrupts++;
	switch (eDhtState)
	{
		case DHT_HOST_PULL_DOWN:
		{
			if (u8NumberOfTimerInterrupts >= 10)
			{
				u8NumberOfTimerInterrupts = 0;
				IO004_SetOutputValue(IO004_Handle0, 1);
				eDhtState = DHT_HOST_PULL_UP;
			}
		} break;

		case DHT_HOST_PULL_UP:
		{
			if (IO004_ReadPin(IO004_Handle0) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_DOWN;
			}
		} break;

		case DHT_SENSOR_PULL_DOWN:
		{
			if (IO004_ReadPin(IO004_Handle0) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_UP;
			}
		} break;

		case DHT_SENSOR_PULL_UP:
		{
			if (IO004_ReadPin(IO004_Handle0) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PREPARE_SENDING;
			}
		} break;

		case DHT_SENSOR_PREPARE_SENDING:
		{
			if (IO004_ReadPin(IO004_Handle0) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_READ_BIT;
			}
		} break;

		case DHT_SENSOR_READ_BIT:
		{
			if (IO004_ReadPin(IO004_Handle0) == 0)
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
				if (u8NumberOfRecvBits == 48)
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
			SYSTM002_StopTimer(TimerId);
		} break;

		default:
		{

		}break;
	}
}

void DHT_Init()
{
	TimerId = SYSTM002_CreateTimer(100,SYSTM002_PERIODIC,TimerHandlerReadSensors,NULL);
}

void DHT_Read()
{
	IO004_SetOutputValue(IO004_Handle0, 0);
	eDhtState = DHT_HOST_PULL_DOWN;
	SYSTM002_StartTimer(TimerId);
}

