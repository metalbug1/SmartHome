/*
 * Main.c
 *
 *  Created on: May 15, 2016
 *      Author: Mihai
 */





#include <DAVE3.h>			//Declarations from DAVE3 Code Generation (includes SFR declaration)
#include "Sensors.h"
#include "SmartHome_Types.h"

RoomInformationType roomInformation[NUMBER_OF_ROOMS];

int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)
	uint8_t data[3] = {'a','b','c'};
	uint16_t i = 0;
	uint16_t BedroomTemperature;
	uint16_t BedroomLight;
	uint16_t BedroomHumidity;
	DAVE_Init();			// Initialization of DAVE Apps

    ADC001_GenerateLoadEvent(&ADC001_Handle0);

	while(1)
	{
    	GetTemperature(roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature);
    	GetLight(roomInformation[ROOM_INDEX(BEDROOM)].u8Light);
    	GetHumidity(roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity);
        ADC001_GenerateLoadEvent(&ADC001_Handle0);

		UART001_WriteDataBytes(&UART001_Handle0,data,3);
		for (i = 0; i<0xFFFF; i++);

	}
	return 0;
}
