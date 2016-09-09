#ifndef _TSL2561_H
#define _TSL2561_H

#define TSL2561_ADDRESS 	(0x39U)

#define TSL_CMD_RW_WORD 	(0xA0U)
#define TSL_CMD_RW_BLOCK 	(0x90U)

#define TSL_CMD_CLEAR_INT 	(0x40U)

#define TSL_DISABLE			(0x0U)
#define TSL_ENABLE			(0x3U)

typedef enum
{
	TSL_IDLE 		= 0x0U,
	TSL_FINISHED 	= 0x1U
} TSL_StateType;

typedef enum
{
	TSL_CONTROL 		= 0x0U,
	TSL_TIMING 			= 0x1U,
	TSL_THRESHLOWLOW 	= 0x2U,
	TSL_THRESHLOWHIGH 	= 0x3U,
	TSL_THRESHHIGHLOW 	= 0x4U,
	TSL_THRESHHIGHHIGH 	= 0x5U,
	TSL_INTERRUPT 		= 0x6U,
	TSL_CRC 			= 0x8U,
	TSL_ID 				= 0xAU,
	TSL_DATA0LOW 		= 0xCU,
	TSL_DATA0HIGH 		= 0xDU,
	TSL_DATA1LOW 		= 0xEU,
	TSL_DATA1HIGH 		= 0xFU
} TSL_RegisterAddressType;

uint8_t TSL_ReadRegister(TSL_RegisterAddressType registerAddress);
void TSL_WriteRegister(TSL_RegisterAddressType registerAddress, uint8_t data);
float TSL_ReadLightIntensity();

void TSL_Start();

#endif //_TSL2561_H
