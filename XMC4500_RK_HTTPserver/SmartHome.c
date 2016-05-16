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



int main(void)
{
	struct tcp_pcb *mypcb;
	uint8_t data[] = {1,2,3};
	uint16_t LivingRoomTemperature;
	uint16_t LivingRoomLight;


	DAVE_Init();			// Initialization of DAVE Apps

    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedDataQueue);
    ADC001_GenerateLoadEvent(&ADC001_Handle0);

    while(1)
	{
    	UpdateSensorInformation();

    	roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature[0] = roomInformation[ROOM_INDEX(LIVING)].u8Temperature[0];
    	roomInformation[ROOM_INDEX(BEDROOM)].u8Temperature[1] = roomInformation[ROOM_INDEX(LIVING)].u8Temperature[1];

    	roomInformation[ROOM_INDEX(BEDROOM)].u8Light[0] = roomInformation[ROOM_INDEX(LIVING)].u8Light[0];
    	roomInformation[ROOM_INDEX(BEDROOM)].u8Light[1] = roomInformation[ROOM_INDEX(LIVING)].u8Light[1];

    	roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity[0] = roomInformation[ROOM_INDEX(LIVING)].u8Humidity[0];
    	roomInformation[ROOM_INDEX(BEDROOM)].u8Humidity[1] = roomInformation[ROOM_INDEX(LIVING)].u8Humidity[1];

        ADC001_GenerateLoadEvent(&ADC001_Handle0);
		ProcessReceivedData();
	}
	return 0;
}

