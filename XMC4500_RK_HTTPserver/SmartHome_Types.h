/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*********************************************************************/


#ifndef _SMARTHOME_TYPES_H
#define _SMARTHOME_TYPES_H

#define NUMBER_OF_ROOMS 	(5)
#define NUMBER_OF_SENSORS	(4)

#define ROOM_INDEX(room)    (((room) >> 0x4) - 0xA)
#define SENSOR_TYPE_MASK	(0xF)

/* This will be the most significant 4 bits of the address byte */
typedef enum
{
	BEDROOM 		= 0xA0,
	LIVING 			= 0xB0,
	KITCHEN			= 0xC0,
	BATHROOM		= 0xD0,
	BALCONY 		= 0xE0
}RoomType;

typedef enum
{
	TEMPERATURE = 0x1,
	HUMIDITY 	= 0x2,
	LIGHT 		= 0x3,
	PRESENCE 	= 0x4
}SensorType;

typedef struct
{
	uint8_t u8Temperature;
	uint8_t u8Humidity;
	uint8_t u8Light;
	uint8_t u8Presence;
}RoomInformationType;

typedef struct
{
	uint8_t au8dataBuffer[256];
	uint8_t u8rxIndex;
	uint8_t u8currentIndex;
}DataQueueType;


#endif
