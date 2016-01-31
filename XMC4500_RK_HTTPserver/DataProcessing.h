/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Initial version						 */
/*********************************************************************/


#ifndef _DATAPROCESSING_H
#define _DATAPROCESSING_H

#include <DAVE3.h>
#include "SmartHome_Types.h"
#include "DataQueue.h"

extern RoomInformationType roomInformation[];
extern DataQueueType receivedDataQueue;

uint8_t convertToCharArray(uint8_t *sensorInformation, uint8_t size, char *characters);

void ProcessReceivedData();

#endif
