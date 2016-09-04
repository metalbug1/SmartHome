/* ###################################################################
**     Filename    : main.c
**     Project     : LowPowerTesting
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-03, 11:48, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Bit1.h"
#include "DHT22Pin.h"
#include "DHT22Timer.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "TSL2561Timer.h"
#include "TimerIntLdd2.h"
#include "TSL2561.h"
#include "TU2.h"
#include "AS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include <stdio.h>

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "dht.h"
#include "TSL2561.h"
#include "SmartHome_Types.h"

#ifdef USE_ENCRYPTION
#include "CRYPTO_AES/crypto_aes.h"

const uint8_t key[] = "disertatieReteaS";
uint8_t encryptedData[16]; // Holds the decryption output
#endif

char OutData[16];
extern uint16_t u16Humidity;
extern uint16_t u16Temperature;
extern float fLightIntensity;
extern TSL_StateType TslSensorState;
extern DHT_State eDhtState;

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	LDD_TDeviceData *bit1Ptr;
	LDD_TDeviceData *MySerialPtr;
	
	volatile int i =0;

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  bit1Ptr = Bit1_Init((LDD_TUserData *)NULL);
  MySerialPtr = AS1_Init(NULL);
  DHT_Read();
  TSL_Start();
  
  while ((TslSensorState != TSL_FINISHED) || (eDhtState != DHT_FINISHED));
 
  OutData[0] = (BEDROOM | TEMPERATURE);
  OutData[1] = (u16Temperature / 10);
  OutData[2] = (u16Temperature % 10);
  OutData[3] = (BEDROOM | HUMIDITY);
  OutData[4] = (u16Humidity / 10);
  OutData[5] = (u16Humidity % 10);
  OutData[6] = (BEDROOM | LIGHT);
  OutData[7] = (uint8_t)((uint16_t)fLightIntensity >> 8U);
  OutData[8] = (uint8_t)((uint16_t)fLightIntensity & 0xFF);
  
#ifdef USE_ENCRYPTION
	CRYPTO_AES_Init(&CRYPTO_AES_0);
	
	CRYPTO_AES_Reset(&CRYPTO_AES_0);
	CRYPTO_AES_SetKey(&CRYPTO_AES_0, key, AES_ENCRYPT);
	CRYPTO_AES_Encrypt(&CRYPTO_AES_0, &encryptedData, OutData, 16);
	AS1_SendBlock(MySerialPtr, encryptedData, 16); 
#else
  AS1_SendBlock(MySerialPtr, OutData, 9); 
#endif
  /*Cpu_SetOperationMode(DOM_STOP, NULL, NULL);*/
  while (1)
  {
	  Bit1_SetVal(&bit1Ptr);
	  for (i = 0; i < 0xFFFFF; i++);
	  Bit1_ClrVal(&bit1Ptr);
	  for (i = 0; i < 0xFFFFF; i++);
  }
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
