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
#include "DataProcessing.h"
#include "WebServerFunctions.h"
#include "Sensors.h"


uint8_t u8NumberOfTimerPeriods = 0;

void TimerHandlerReadSensors()
{
    //ADC001_GenerateLoadEvent(&ADC001_Handle0);
	//UpdateSensorInformation();
	u8NumberOfTimerPeriods++;
}

int main(void)
{
	handle_t TimerId;
	DAVE_Init();			// Initialization of DAVE Apps

    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedDataQueue);

    TimerId = SYSTM001_CreateTimer(100,SYSTM001_PERIODIC,TimerHandlerReadSensors,NULL);
    SYSTM001_StartTimer(TimerId);

   // ADC001_GenerateLoadEvent(&ADC001_Handle0);
    while(1)
	{

		if (u8NumberOfTimerPeriods >= 100)
		{
			u8NumberOfTimerPeriods = 0;
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature[0] = roomInformation[ROOM_INDEX(LIVING)].u8Temperature[0];
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature[1] = roomInformation[ROOM_INDEX(LIVING)].u8Temperature[1];
//
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Light[0] = roomInformation[ROOM_INDEX(LIVING)].u8Light[0];
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Light[1] = roomInformation[ROOM_INDEX(LIVING)].u8Light[1];
//
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity[0] = roomInformation[ROOM_INDEX(LIVING)].u8Humidity[0];
//	    	roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity[1] = roomInformation[ROOM_INDEX(LIVING)].u8Humidity[1];

			ProcessReceivedData();
		}
	}
	return 0;
}

