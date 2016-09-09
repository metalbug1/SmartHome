/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/

#include "DataProcessing.h"
#include "Sensors.h"
#include "Room.h"
#ifdef USE_ENCRYPTION
#include "CRYPTO_AES/crypto_aes.h"
#endif

DataQueueType receivedDataQueue;
RoomInformationType roomInformation[NUMBER_OF_ROOMS];
static RoomType currentRoom 		= BEDROOM;
static SensorType currentSensor 	= TEMPERATURE;
static uint8_t currentDataIndex 	= 0x0;

void UART_ReceiveInterrupt(void)
{
	uint16_t au16tempBuffer[256];
	uint16_t u16numberOfReceivedBytes;

	u16numberOfReceivedBytes = UART001_ReadDataMultiple(&UART001_Handle0, au16tempBuffer, QUEUE_MAX_SIZE);

	Queue_PutBuffer(&receivedDataQueue, (uint8_t*)au16tempBuffer, u16numberOfReceivedBytes);
}

void UpdateSensorInformation()
{
	GetTemperature(roomInformation[ROOM_INDEX(CURRENT_ROOM)].u8Temperature);
	GetLight(roomInformation[ROOM_INDEX(CURRENT_ROOM)].u8Light);
	GetHumidity(roomInformation[ROOM_INDEX(CURRENT_ROOM)].u8Humidity);
}

uint8_t convertToCharArray(uint8_t *sensorInformation, uint8_t size, char *characters)
{
	uint8_t numberOfCharacters = 0;
	uint8_t tempIndex = 0;
	uint8_t tempData;
	bool foundFirstDigit = FALSE;

	while (tempIndex < size)
	{
		foundFirstDigit = FALSE;
		tempData = sensorInformation[tempIndex];

		if ((tempData / 100) != 0)
		{
			characters[numberOfCharacters] = (char)((tempData / 100) + 0x30);
			numberOfCharacters++;
			tempData = tempData - (100 * (characters[numberOfCharacters - 1] - 0x30));
			foundFirstDigit = TRUE;
		}

		if ((TRUE == foundFirstDigit) || ((tempData / 10) != 0))
		{
			characters[numberOfCharacters] = (char)((tempData / 10) + 0x30);
			numberOfCharacters++;
			tempData = tempData - (10 * (characters[numberOfCharacters - 1] - 0x30));
		}
		characters[numberOfCharacters] = (char)((tempData) + 0x30);
		numberOfCharacters++;

		tempIndex++;
		if (tempIndex < size)
		{
			characters[numberOfCharacters] = '.';
			numberOfCharacters++;
		}
	}

	return numberOfCharacters;
}


static bool IsAddress(uint8_t byte)
{
	bool ret = FALSE;

	if (((byte & SENSOR_TYPE_MASK) <= NUMBER_OF_SENSORS) && (ROOM_INDEX(byte) < NUMBER_OF_ROOMS) && (byte >= BEDROOM))
	{
		ret = TRUE;
	}

	return ret;
}

void ProcessReceivedData()
{
	uint8_t tempData[QUEUE_MAX_SIZE];
	uint8_t tempIndex = 0;
	uint8_t tempLength = 0;
#ifdef USE_ENCRYPTION
	uint8_t encryptedData[QUEUE_MAX_SIZE];
#endif

	if (FALSE == Queue_IsEmpty(receivedDataQueue))
	{
		tempLength = receivedDataQueue.u8usedSpace;

#ifdef USE_ENCRYPTION

		Queue_GetBuffer(&receivedDataQueue, encryptedData, tempLength);
		CRYPTO_AES_Decrypt(&CRYPTO_AES_0, tempData, encryptedData, tempLength);
#else

		Queue_GetBuffer(&receivedDataQueue, tempData, tempLength);
#endif
		for (tempIndex = 0; tempIndex < tempLength; tempIndex++)
		{
			if (IsAddress(tempData[tempIndex]))
			{
				currentRoom = tempData[tempIndex] & ROOM_TYPE_MASK;
				currentSensor = tempData[tempIndex] & SENSOR_TYPE_MASK;
				currentDataIndex = 0;
			}
			else
			{
				switch (currentSensor)
				{
					case TEMPERATURE:
						if (currentDataIndex < TEMP_MAX_BYTES)
						{
							roomInformation[ROOM_INDEX(currentRoom)].u8Temperature[currentDataIndex] = tempData[tempIndex];
							currentDataIndex++;
						}
						break;
					case HUMIDITY:
						if (currentDataIndex < HUMID_MAX_BYTES)
						{
							roomInformation[ROOM_INDEX(currentRoom)].u8Humidity[currentDataIndex] = tempData[tempIndex];
							currentDataIndex++;
						}
						break;
					case LIGHT:
						if (currentDataIndex < LIGHT_MAX_BYTES)
						{
							roomInformation[ROOM_INDEX(currentRoom)].u8Light[currentDataIndex] = tempData[tempIndex];
							currentDataIndex++;
						}
						break;
					case PRESENCE:
						if (currentDataIndex < PIR_MAX_BYTES)
						{
							roomInformation[ROOM_INDEX(currentRoom)].u8Presence[currentDataIndex] = tempData[tempIndex];
							currentDataIndex++;
						}
						break;
					default:
						break;

				}
			}
		}
	}
}

