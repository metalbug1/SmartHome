/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/

#include <DAVE3.h>
#include "netconf.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.h"
#include "DataProcessing.h"
#include "WebServerFunctions.h"


const char *CGI_led_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);
u16_t SSI_Handler (int iIndex, char *pcInsert, int iInsertLen);

char const TAGCHAR[1] 	="t";
char const TAGCHAR2[1] 	="u";
char const TAGCHAR3[1] 	="l";
char const* TAGS[3] 	= {TAGCHAR, TAGCHAR2, TAGCHAR3};

/* Htm request for "/leds.cgi" will start led_handler */
/*<form method="get" action="/leds.cgi">*/
const tCGI LED_CGI={"/leds.cgi", CGI_led_handler};

/* Cgi call table, only one CGI used */
tCGI CGI_TAB[1];

/* Initialization of functions to be used with CGi*/
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

//Initialize cgi environment
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

	if (iIndex == 0)
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

	   return numberOfChars;
	}

	if (iIndex == 2)
	{
		uint16_t light = ( roomInformation[ROOM_INDEX(BEDROOM)].u8Light[0] << 8 ) + roomInformation[ROOM_INDEX(BEDROOM)].u8Light[1];
		sprintf (tempChars, "%d", light);
		if (light == 0)
		{
			numberOfChars = 1;
		}
		else
		{
			numberOfChars = 0;
			while (light !=0)
			{
				light /= 10;
				numberOfChars++;
			}
		}
		/* prepare data to be inserted in html */
		for (tempIndex = 0; tempIndex < numberOfChars; tempIndex++)
		{
			*(pcInsert + tempIndex)		= tempChars[tempIndex];
		}

	   return numberOfChars;
	}

	return 0;
}


void http_SSI_init (void)
{
	/*
	SSI is a method used to dynamically include dynamic data in HTML code.
	This done by placing a specific tag inside the HTML code of the web page. The tag should
	have the following format: <!--#tag-->
	For the ADC conversion page, the following tag "t" is used inside the HTML code: <!--#t-->
	*/
	http_set_ssi_handler(SSI_Handler, (char const **)TAGS, 3);
}
