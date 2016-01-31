/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Added processingData functions		 */
/*********************************************************************/


/** Inclusion of header file */
#include <DAVE3.h>
#include "netconf.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.h"

#include "SmartHome_Types.h"
#include "DataQueue.h"


RoomInformationType roomInformation[NUMBER_OF_ROOMS];

RoomType currentRoom 		= BEDROOM;
SensorType currentSensor 	= TEMPERATURE;
uint8_t currentData 		= 0x0;
uint8_t currentDataIndex 	= 0x0;

uint8_t convertToCharArray(uint8_t *sensorInformation, uint8_t size, char *characters)
{
	uint8_t numberOfCharacters = 0;
	uint8_t tempIndex;
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
			characters[numberOfCharacters] = ',';
			numberOfCharacters++;
		}
	}

	return numberOfCharacters;
}

/* Initialisation of functions to be used with CGi*/
//  CGI handler to switch LED status
const char *CGI_led_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{

	uint32_t i=0;
	
	/* We have only one CGI handler iIndex = 0 */
	if (iIndex==0)
	{

	  /* Check cgi parameter : example GET /leds.cgi?led=2&led=4 */
	  for (i=0; i<iNumParams; i++)
	  {
		/* check parameter "led" */
		if (strcmp(pcParam[i] , "led")==0)	 
		{
		  /* switch led1 ON if 1 */
		  if(strcmp(pcValue[i], "1") ==0) 
				IO004_TogglePin(IO004_Handle0);
			
		  /* switch led2 ON if 2 */
		  else if(strcmp(pcValue[i], "2") ==0) 
				IO004_TogglePin(IO004_Handle0);
		}
	  }
	}
	/* uri to send after cgi call*/


	return "/LED.htm";


}



/* Htm request for "/leds.cgi" will start led_handler */
/*<form method="get" action="/leds.cgi">*/
const tCGI LED_CGI={"/leds.cgi", CGI_led_handler};

/* Cgi call table, only one CGI used */
tCGI CGI_TAB[1];



//Initialise cgi environment
void http_CGI_init( void)
{
	//Initialised CGI structure for LED
	CGI_TAB[0] = LED_CGI;

	// Set CGI
	http_set_cgi_handlers(&CGI_TAB[0], 1);
}

u16_t SSI_Handler (int iIndex, char *pcInsert, int iInsertLen)
{
	uint16_t numberOfChars;
	uint8_t tempIndex;
	char tempChars[6];

	if (iIndex ==0)
	{
		numberOfChars = convertToCharArray(roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature, TEMP_MAX_BYTES, tempChars);
		/* prepare data to be inserted in html */
		for (tempIndex = 0; tempIndex < numberOfChars; tempIndex++)
		{
			*(pcInsert + tempIndex)		= tempChars[tempIndex];
		}
	   
	   return numberOfChars;

	}

	if (iIndex == 1)
	{
		numberOfChars = convertToCharArray(roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity, HUMID_MAX_BYTES, tempChars);
		/* prepare data to be inserted in html */
		for (tempIndex = 0; tempIndex < numberOfChars; tempIndex++)
		{
			*(pcInsert + tempIndex)		= tempChars[tempIndex];
		}

	   /* 4 characters need to be inserted in html*/
	   return numberOfChars;
	}

	return 0;
}



char const* TAGCHAR="t";
char const* TAGCHAR2="u";
char const** TAGS= {&TAGCHAR, &TAGCHAR2};


void http_SSI_init (void)
{
	/*
	SSI is a method used to dynamically include dynamic data in HTML code.
	This done by placing a specific tag inside the HTML code of the web page. The tag should
	have the following format: <!--#tag-->
	For the ADC conversion page, the following tag "t" is used inside the HTML code: <!--#t-->
	*/
	http_set_ssi_handler(SSI_Handler, (char const **)TAGS, 2);
}


DataQueueType receivedData;

void UART_ReceiveInterrupt(void)
{
	uint16_t au16tempBuffer[256];
	uint16_t u16numberOfReceivedBytes;

	u16numberOfReceivedBytes = UART001_ReadDataMultiple(&UART001_Handle0, au16tempBuffer, QUEUE_MAX_SIZE);

	Queue_PutBuffer(&receivedData, (uint8_t*)au16tempBuffer, u16numberOfReceivedBytes);
}

bool IsAddress(uint8_t byte)
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

	if (FALSE == Queue_IsEmpty(receivedData))
	{
		tempLength = receivedData.u8usedSpace;
		Queue_GetBuffer(&receivedData, tempData, tempLength);

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

int main(void)
{
	uint8_t k = 0;
	char buff[3];

 	DAVE_Init();			// Initialization of DAVE Apps

	ADC002_InitializeQueue((ADC002_HandleType*)&ADC002_Handle0);
    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedData);

	while(1)
	{
		ProcessReceivedData();
	/*	if ((k == 0) && roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity[1] != 0)
		{
			UART001_WriteDataBytes(&UART001_Handle0, roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature, 2);
			UART001_WriteDataBytes(&UART001_Handle0, roomInformation[ROOM_INDEX(BEDROOM)].u8Light, 2);


			convertToCharArray(roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity, 2, buff);
			k = 1;
		}*/

	}
	return 0;
}
