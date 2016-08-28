/*
 * main.c
 *
 *  Created on: 2016 Aug 28 12:28:02
 *  Author: Mihai
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)
#include <stdio.h>
#include "dht.h"
#include "TSL2561.h"

extern DHT_State eDhtState;
extern uint16_t u16Humidity;
extern uint16_t u16Temperature;
extern float fLightIntensity;

uint8_t light;


uint8_t mesajStart[] = "\nStartup\n";
uint8_t mesajDht[] = "\nSensors are read!\n";
uint8_t mesajSleep[] = "\nIntru in sleep\n";
uint8_t mesajRTC[] = "\nA trecut 1 minut\n";



uint8_t HumSiTemp[100];

void RtcHandler(void)
{
	UART_Transmit(&UART_0, mesajRTC, sizeof(mesajRTC)/sizeof(uint8_t));
}

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */


  UART_Transmit(&UART_0, mesajStart, sizeof(mesajStart)/sizeof(uint8_t));
  while(UART_IsTxBusy(&UART_0));


  if(status == DAVE_STATUS_FAILURE)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /*UART_Transmit(&UART_0, mesajStart, sizeof(mesajStart)/sizeof(uint8_t));*/
  DHT_Init();
  DHT_Read();
  TSL_Start();

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  if (eDhtState == DHT_FINISHED && fLightIntensity!=0)
	  {
		  UART_Transmit(&UART_0, mesajDht, sizeof(mesajDht)/sizeof(uint8_t));
		  while(UART_IsTxBusy(&UART_0));

		  light = (uint8_t)(fLightIntensity * 10);
		  sprintf(HumSiTemp, "\nHum = %d.%d, Temp= %d.%d, Light= %d.%d",u16Humidity/10,u16Humidity%10, u16Temperature/10, u16Temperature%10, light/10, light%10);

		  UART_Transmit(&UART_0, HumSiTemp, sizeof(HumSiTemp)/sizeof(uint8_t));
		  while(UART_IsTxBusy(&UART_0));
		  eDhtState = DHT_IDLE;

		  UART_Transmit(&UART_0, mesajSleep, sizeof(mesajSleep)/sizeof(uint8_t));
		  while(UART_IsTxBusy(&UART_0));

		  RTC_Start();
		/*  XMC_SCU_HIB_EnableEvent(XMC_SCU_HIB_EVENT_WAKEUP_ON_RTC);
		  XMC_SCU_HIB_EnterHibernateState();*/


	  }

  }
}
