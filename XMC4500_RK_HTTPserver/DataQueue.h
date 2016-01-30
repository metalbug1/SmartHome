/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*********************************************************************/


#ifndef _DATAQUEUE_H
#define _DATAQUEUE_H

#include <DAVE3.h>
#include "SmartHome_Types.h"

#define QUEUE_MAX_SIZE		(255)

typedef struct
{
	uint8_t au8dataBuffer[QUEUE_MAX_SIZE];
	uint8_t u8rxIndex;
	uint8_t u8processingIndex;
	uint8_t u8usedSpace;
}DataQueueType;

void Queue_Init(DataQueueType *dq);

bool Queue_IsEmpty(DataQueueType dq);

bool Queue_IsFull(DataQueueType dq);

uint8_t Queue_PutByte(DataQueueType *dq, uint8_t byte );

StdReturnType Queue_PutBuffer(DataQueueType *dq, uint8_t *dataBuffer, uint8_t numberOfBytes);

StdReturnType Queue_GetByte(DataQueueType *dq, uint8_t *byte);

StdReturnType Queue_GetBuffer(DataQueueType *dq, uint8_t *buff, uint8_t numberOfBytes);

#endif
