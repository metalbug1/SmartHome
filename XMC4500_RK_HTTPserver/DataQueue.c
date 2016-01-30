/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*********************************************************************/

#include "DataQueue.h"


void Queue_Init(DataQueueType *dq)
{
	dq->u8processingIndex = 0;
	dq->u8rxIndex = 0;
	dq->u8usedSpace = 0;
}

bool Queue_IsEmpty(DataQueueType dq)
{
	return (0 == dq.u8usedSpace);
}

bool Queue_IsFull(DataQueueType dq)
{
	return (QUEUE_MAX_SIZE == dq.u8usedSpace);
}

uint8_t Queue_PutByte(DataQueueType *dq, uint8_t byte )
{
	StdReturnType ret = NOT_OK;

	if (NOT_OK == Queue_IsFull(*dq))
	{
		dq->au8dataBuffer[dq->u8rxIndex] = byte;
		if (dq->u8rxIndex == QUEUE_MAX_SIZE - 1 )
		{
			dq->u8rxIndex = 0;
		}
		else
		{
			dq->u8rxIndex++;
		}
		dq->u8usedSpace++;
		ret = OK;
	}

  return ret;
}

StdReturnType Queue_PutBuffer(DataQueueType *dq, uint8_t *dataBuffer, uint8_t numberOfBytes)
{
	StdReturnType ret = NOT_OK;
	uint8_t u8tempIndex;

	if ((QUEUE_MAX_SIZE - dq->u8usedSpace) >= numberOfBytes)
	{
		while ( u8tempIndex < numberOfBytes )
		{
	      dq->au8dataBuffer[dq->u8rxIndex] = dataBuffer[u8tempIndex];
	      if (dq->u8rxIndex == QUEUE_MAX_SIZE - 1)
	      {
	    	  dq->u8rxIndex = 0;
	      }
	      else
	      {
	    	  dq->u8rxIndex++;
	      }
	      dq->u8usedSpace++;
	      u8tempIndex++;
		}
	    ret = OK;
	  }
	  return ret;
}


StdReturnType Queue_GetByte(DataQueueType *dq, uint8_t *byte)
{
	StdReturnType ret = NOT_OK;

	if (FALSE == Queue_IsEmpty(*dq))
	{
		*byte = dq->au8dataBuffer[dq->u8processingIndex];
		if (dq->u8processingIndex == (QUEUE_MAX_SIZE - 1))
		{
			dq->u8processingIndex = 0;
		}
		else
		{
			dq->u8processingIndex++;
		}
		dq->u8usedSpace--;
		ret = OK;
  }

	return ret;
}

StdReturnType Queue_GetBuffer(DataQueueType *dq, uint8_t *buff, uint8_t numberOfBytes)
{
	StdReturnType ret = NOT_OK;
	uint8_t u8Index = 0;

	if (dq->u8usedSpace >= numberOfBytes )
	{
		while (u8Index < numberOfBytes)
		{
			buff[u8Index] = dq->au8dataBuffer[dq->u8processingIndex];
			if (dq->u8processingIndex == (QUEUE_MAX_SIZE - 1))
			{
				dq->u8processingIndex = 0;
			}
			else
			{
				dq->u8processingIndex++;
			}
				dq->u8usedSpace--;
				u8Index++;
			}
		ret = OK;
	}

	return ret;
}
