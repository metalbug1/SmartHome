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


int main(void)
{
 	DAVE_Init();			// Initialization of DAVE Apps

	ADC002_InitializeQueue((ADC002_HandleType*)&ADC002_Handle0);
    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedDataQueue);

	while(1)
	{
		ProcessReceivedData();

	}
	return 0;
}
