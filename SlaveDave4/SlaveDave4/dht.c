#include <DAVE.h>
#include "dht.h"

DHT_State eDhtState = DHT_IDLE;
uint8_t u8NumberOfRecvBits = 0;
uint8_t u8NumberOfTimerInterrupts = 0;
uint16_t u16Humidity = 0;
uint16_t u16Temperature = 0;
uint16_t u16Aux = 0;

void TimerHandlerReadDHT22()
{
	TIMER_ClearEvent(&Timer_DHT22);

	u8NumberOfTimerInterrupts++;
	switch (eDhtState)
	{
		case DHT_HOST_PULL_DOWN:
		{
			if (u8NumberOfTimerInterrupts >= 100)
			{
				u8NumberOfTimerInterrupts = 0;
				DIGITAL_IO_SetOutputHigh(&DHT22_PIN);
				eDhtState = DHT_HOST_PULL_UP;
			}
		} break;

		case DHT_HOST_PULL_UP:
		{
			if (DIGITAL_IO_GetInput(&DHT22_PIN) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_DOWN;
			}
		} break;

		case DHT_SENSOR_PULL_DOWN:
		{
			if (DIGITAL_IO_GetInput(&DHT22_PIN) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PULL_UP;
			}
		} break;

		case DHT_SENSOR_PULL_UP:
		{
			if (DIGITAL_IO_GetInput(&DHT22_PIN) == 0)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_PREPARE_SENDING;
			}
		} break;

		case DHT_SENSOR_PREPARE_SENDING:
		{
			if (DIGITAL_IO_GetInput(&DHT22_PIN) == 1)
			{
				u8NumberOfTimerInterrupts = 0;
				eDhtState = DHT_SENSOR_READ_BIT;
			}
		} break;

		case DHT_SENSOR_READ_BIT:
		{
			if (DIGITAL_IO_GetInput(&DHT22_PIN) == 0)
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
			TIMER_Stop(&Timer_DHT22);
		} break;

		default:
		{

		}break;
	}
}

void DHT_Init()
{
	TIMER_SetTimeInterval(&Timer_DHT22, 1000);
}

void DHT_Read()
{
	DIGITAL_IO_SetOutputLow(&DHT22_PIN);
	eDhtState = DHT_HOST_PULL_DOWN;
	TIMER_Start(&Timer_DHT22);
}

