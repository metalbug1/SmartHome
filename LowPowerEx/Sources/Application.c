/*
 
* Application.c
*
*  Created on: Mar 16, 2014
*      Author: Erich Styger
*/
 
/* Including shared modules, which are used for whole project */
#include "Cpu.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Application.h"
#include "LPTMR_PDD.h"
#include "BlueLed.h"
#include "WakeUpTimer.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "HmTrpUart.h"
#include "RedLed.h"
#include "DHT22Pin.h"
#include "DHT22Timer.h"
#include "TSL2561Timer.h"
#include "MeasurePin.h"
#include "TSL2561.h"
#include "dht.h"
#include "I2C_PDD.h"
#include "i2c.h"
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
extern bool sensorRead;

LDD_TDeviceData *MeasurePinHandler;
LDD_TDeviceData *blueLedHandler;
LDD_TDeviceData *redLedHandler;
LDD_TDeviceData *uartHandler;

int UartTxFinished = 0;

void APP_OnLLSWakeUpInterrupt(void) 
{
  uint32_t tmp;
 
  tmp = Cpu_GetLLSWakeUpFlags();
  if (tmp&LLWU_INT_MODULE0) { /* LPTMR */
    LPTMR_PDD_ClearInterruptFlag(LPTMR0_BASE_PTR); /* Clear interrupt flag */
  }
}
 
void APP_TimerInterrupt(void) 
{
  BlueLed_NegVal(&blueLedHandler);
}
void APP_Run(void) 
{
	volatile int i = 0;
	blueLedHandler = BlueLed_Init((LDD_TUserData *)NULL);
	redLedHandler = RedLed_Init((LDD_TUserData *)NULL);
	MeasurePinHandler = MeasurePin_Init((LDD_TUserData *)NULL);
	
	init_I2C();
	MeasurePin_ClrVal(&MeasurePinHandler);

	TSL_Start();
	while (TslSensorState != TSL_FINISHED);

#ifdef USE_ENCRYPTION

	CRYPTO_AES_Init(&CRYPTO_AES_0);

	CRYPTO_AES_Reset(&CRYPTO_AES_0);
	CRYPTO_AES_SetKey(&CRYPTO_AES_0, key, AES_ENCRYPT);
#endif
	while(1) 
	{
		
		RedLed_NegVal(&redLedHandler);
		for (i = 0; i < 0xFFFF; i++);
		RedLed_NegVal(&redLedHandler);
		for (i = 0; i < 0xFFFF; i++);
		uartHandler = HmTrpUart_Init(NULL);

		DHT_Read();
		while (eDhtState != DHT_FINISHED);
		
		if (sensorRead == 1)
		{
			TslSensorState = TSL_IDLE;
			fLightIntensity = TSL_ReadLightIntensity();
			TslSensorState = TSL_FINISHED;
		}
		while (TslSensorState != TSL_FINISHED);
	
		OutData[0] = (BEDROOM | TEMPERATURE);
		OutData[1] = (u16Temperature / 10);
		OutData[2] = (u16Temperature % 10);
		OutData[3] = (BEDROOM | HUMIDITY);
		OutData[4] = (u16Humidity / 10);
		OutData[5] = (u16Humidity % 10);
		OutData[6] = (BEDROOM | LIGHT);
		OutData[7] = (uint8_t) ((uint16_t) fLightIntensity >> 8U);
		OutData[8] = (uint8_t) ((uint16_t) fLightIntensity & 0xFF);
		UartTxFinished = 0;
#ifdef USE_ENCRYPTION
		CRYPTO_AES_Encrypt(&CRYPTO_AES_0, &encryptedData, OutData, 16);
		HmTrpUart_SendBlock(uartHandler, encryptedData, 16);
#else
		MeasurePin_NegVal(&MeasurePinHandler);
		HmTrpUart_SendBlock(uartHandler, OutData, 9);
#endif
		while (UartTxFinished == 0);
		MeasurePin_NegVal(&MeasurePinHandler);
	    Cpu_SetOperationMode(DOM_STOP, NULL, NULL); /* next interrupt will wake us up */
  }
}
