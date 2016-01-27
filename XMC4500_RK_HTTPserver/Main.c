/*
 * Main.c
 *
 *  Created on: Mar 18, 2013
 *      Author: toochang
 */





/** Inclusion of header file */
#include <DAVE3.h>
#include "netconf.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.h"



/* Initialisation of functions to be used with CGi*/
//  CGI handler to switch LED status
const char *CGI_led_handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{

	uint32_t i=0;
	
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

u16_t SSI_Temp_Handler (int iIndex, char *pcInsert, int iInsertLen)
{

    char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    uint16_t ADCVal = 0;        
	status_t status;


	/* We have only one SSI handler iIndex = 0 */

	if (iIndex ==0)
	{  


	/* get ADC conversion value */

	status = ADCCH001_GetResult(&ADCCH001_Handle0, &ADCVal);
		//ADCVal = AD_result;//ADC_GetConversionValue(ADC3);
		
		/* convert to Voltage,	step = 0.8 mV */
		ADCVal = (uint16_t)(ADCVal * 0.8);	
		
		/* get digits to display */
		
		Digit1= ADCVal/1000;
		Digit2= (ADCVal-(Digit1*1000))/100 ;
		Digit3= (ADCVal-((Digit1*1000)+(Digit2*100)))/10;
		Digit4= ADCVal -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
		   
		/* prepare data to be inserted in html */
		*pcInsert		= (char)(Digit1+0x30);
		*(pcInsert + 1) = (char)(Digit2+0x30);
		*(pcInsert + 2) = (char)(Digit3+0x30);
		*(pcInsert + 3) = (char)(Digit4+0x30);
	   
	   /* 4 characters need to be inserted in html*/
	   return 4;

	}

	if (iIndex == 1)
	{
		*pcInsert		= (char)'c';
		*(pcInsert + 1) = (char)'a';
		*(pcInsert + 2) = (char)'l';
		*(pcInsert + 3) = (char)'d';

	   /* 4 characters need to be inserted in html*/
	   return 4;
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
http_set_ssi_handler(SSI_Temp_Handler, (char const **)TAGS, 2);

}



int main(void)
{
//	status_t status;		// Declaration of return variable for DAVE3 APIs (toggle comment if required)


	DAVE_Init();			// Initialization of DAVE Apps

	ADC002_InitializeQueue((ADC002_HandleType*)&ADC002_Handle0);
    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();
    // ... infinite loop ...
	while(1)
	{

	}
	return 0;
}
