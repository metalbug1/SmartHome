/*
 * Main.c
 *
 *  Created on: May 15, 2016
 *      Author: Mihai
 */

#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "Sensors.h"
#include "Room.h"
#include "SmartHome_Types.h"

#define ROOM_SENSOR_DATA_MAX_SIZE  (20)

uint8_t au8RoomSensorData[ROOM_SENSOR_DATA_MAX_SIZE];
uint8_t u8RoomSensorDataSize = 0;

uint8_t u8NumberOfTimerPeriods = 0;

void PackData()
{
	uint8_t u8RoomSensorDataIndex = 0;
	uint8_t u8SensorDataIndex = 0;
	uint8_t au8BedroomTemperature[TEMP_MAX_BYTES];
	uint8_t au8BedroomHumidity[HUMID_MAX_BYTES];
	uint8_t au8BedroomLight[LIGHT_MAX_BYTES];

	GetTemperature(au8BedroomTemperature);
	GetHumidity(au8BedroomHumidity);
	GetLight(au8BedroomLight);

	/* Add temperature data to the room data buffer */
	au8RoomSensorData[u8RoomSensorDataIndex] = (CURRENT_ROOM | TEMPERATURE);
	u8RoomSensorDataIndex++;

	for (u8SensorDataIndex = 0; u8SensorDataIndex < TEMP_MAX_BYTES; u8SensorDataIndex++)
	{
		au8RoomSensorData[u8RoomSensorDataIndex] = au8BedroomTemperature[u8SensorDataIndex];
		u8RoomSensorDataIndex++;
	}

	/* Add humidity data to the room data buffer */
	au8RoomSensorData[u8RoomSensorDataIndex] = (CURRENT_ROOM | HUMIDITY);
	u8RoomSensorDataIndex++;

	for (u8SensorDataIndex = 0; u8SensorDataIndex < HUMID_MAX_BYTES; u8SensorDataIndex++)
	{
		au8RoomSensorData[u8RoomSensorDataIndex] = au8BedroomHumidity[u8SensorDataIndex];
		u8RoomSensorDataIndex++;
	}

	/* Add light data to the room data buffer */
	au8RoomSensorData[u8RoomSensorDataIndex] = (CURRENT_ROOM | LIGHT);
	u8RoomSensorDataIndex++;

	for (u8SensorDataIndex = 0; u8SensorDataIndex < LIGHT_MAX_BYTES; u8SensorDataIndex++)
	{
		au8RoomSensorData[u8RoomSensorDataIndex] = au8BedroomLight[u8SensorDataIndex];
		u8RoomSensorDataIndex++;
	}

	u8RoomSensorDataSize = u8RoomSensorDataIndex;
}

void TimerHandlerReadSensors()
{
    ADC001_GenerateLoadEvent(&ADC001_Handle0);
	PackData();
	u8NumberOfTimerPeriods++;
}

int main(void)
{
	handle_t TimerId;

	DAVE_Init();			// Initialization of DAVE Apps

    ADC001_GenerateLoadEvent(&ADC001_Handle0);
    TimerId = SYSTM001_CreateTimer(100,SYSTM001_PERIODIC,TimerHandlerReadSensors,NULL);
    SYSTM001_StartTimer(TimerId);
	while(1)
	{
		if (u8NumberOfTimerPeriods >= 100)
		{
			u8NumberOfTimerPeriods = 0;
			UART001_WriteDataBytes(&UART001_Handle0, au8RoomSensorData, u8RoomSensorDataSize);
		}
	}
	return 0;
}
