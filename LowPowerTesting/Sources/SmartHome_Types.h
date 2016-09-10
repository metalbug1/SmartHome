/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Change data type for sensor info
 * 							    to uint8[] and added max sizes		 */
/*********************************************************************/


#ifndef _SMARTHOME_TYPES_H
#define _SMARTHOME_TYPES_H

#define NUMBER_OF_ROOMS 	(5)
#define NUMBER_OF_SENSORS	(4)

#define TEMP_MAX_BYTES 		(2)
#define HUMID_MAX_BYTES 	(2)
#define LIGHT_MAX_BYTES 	(2)
#define PIR_MAX_BYTES		(1)

#define ROOM_INDEX(room)    (((room) >> 0x4) - 0xA)
#define SENSOR_TYPE_MASK	(0x0F)
#define ROOM_TYPE_MASK		(0xF0)

typedef enum
{
	OK = 0,
	NOT_OK = 1
}StdReturnType;

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
	uint8_t u8Temperature[TEMP_MAX_BYTES];
	uint8_t u8Humidity[HUMID_MAX_BYTES];
	uint8_t u8Light[LIGHT_MAX_BYTES];
	uint8_t u8Presence[PIR_MAX_BYTES];
}RoomInformationType;

//#define USE_ENCRYPTION

#endif
