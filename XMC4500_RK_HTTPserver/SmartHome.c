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
#include "TemperatureSensor.h"



int main(void)
{
	struct tcp_pcb *mypcb;
	uint8_t data[] = {1,2,3};
	uint16_t LivingRoomTemperature;


	DAVE_Init();			// Initialization of DAVE Apps

    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedDataQueue);
    TemperatureSensorInit();

    while(1)
	{
    	LivingRoomTemperature = GetTemperature();
		ProcessReceivedData();
	   /* mypcb = tcp_new();
	    tcp_bind(mypcb, IP_ADDR_ANY, 80);
		tcp_write(mypcb, data, 3, TCP_WRITE_FLAG_COPY);*/

	}
	return 0;
}

