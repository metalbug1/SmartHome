
/*CODE_BLOCK_BEGIN[SYSTM002.c]*/

/*******************************************************************************
 Copyright (c) 2014, Infineon Technologies AG                                 **
 All rights reserved.                                                         **
                                                                              **
 Redistribution and use in source and binary forms, with or without           **
 modification,are permitted provided that the following conditions are met:   **
                                                                              **
 *Redistributions of source code must retain the above copyright notice,      **
 this list of conditions and the following disclaimer.                        **
 *Redistributions in binary form must reproduce the above copyright notice,   **
 this list of conditions and the following disclaimer in the documentation    **
 and/or other materials provided with the distribution.                       **
 *Neither the name of the copyright holders nor the names of its contributors **
 may be used to endorse or promote products derived from this software without**
 specific prior written permission.                                           **
                                                                              **
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  **
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    **
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   **
 ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE   **
 LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR         **
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         **
 SUBSTITUTE GOODS OR  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    **
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      **
 CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)       **
 ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   **
 POSSIBILITY OF SUCH DAMAGE.                                                  **
                                                                              **
 To improve the quality of the software, users are encouraged to share        **
 modifications, enhancements or bug fixes with Infineon Technologies AG       **
 dave@infineon.com).                                                          **
                                                                              **
********************************************************************************
**                                                                            **
** PLATFORM : Infineon XMC4000/1000 Series                                    **
**                                                                            **
** COMPILER : Compiler Independent                                            **
**                                                                            **
** AUTHOR   : App Developer                                                   **
**                                                                            **
** NOTE     : Any Changes made to this file will be overwritten during Code   **
**            Generation                                                      **
**                                                                            **
********************************************************************************
** VERSION HISTORY:
********************************************************************************
** v1.0.0, 25 Sept 2013,  SSS: Initial version.
** v1.0.2  10 Oct  2013,  SSS: 1. conditional code is added for all the devices.
**                             2. SYSTM002_GetTime API made as inline function
**                          and change in the code (divided by 1000 is removed)
**                             3.SYSTM002_GetSysTickCount API made as inline 
**                               function. 
**
** v1.0.6  29 Jan  2014,  SSM: 1. DBG002 App changes are taken care.
**                             
** V1.0.8  06 Feb  2014,     : 1. XMC1000 VQFN package support added;   
**                         XMC4000 Device support extended for XMC4500 AC step,
**                                XMC4400 AB Step and XMC4200 AB Step.
**  
** V1.0.10 25 Feb  2014,  SSM: 1. Floating point multiplication and Division     
**                                  inside API are removed. 
**                             2. SYSTM002_GetSysTickCount(uint32_t Period)API 
**                                removed and it is replaced with the macro
**                                SYSTM002_SysTickMicroSec(microsec).
** V1.0.12 23 Apr  2014,  SSM: 1. Fixes Floating operation issue 
**                                in XMC4x series.
**
*******************************************************************************/

/**
 * @file   SYSTM002.c
 *
 * @brief  This file contains public function implementations of SYSTM002.
 *
 */

/**
 * @cond INTERNAL_DOCS
 */

/*******************************************************************************
** INCLUDE FILES:
*******************************************************************************/
/* Included to access app data structure, functions & enumerations */
#include "../../inc/SYSTM002/SYSTM002.h"
#if ((__TARGET_DEVICE__ == XMC44) || (__TARGET_DEVICE__ == XMC42) || \
                   (__TARGET_DEVICE__ == XMC41) || (__TARGET_DEVICE__ == XMC45))
#include "../../inc/CLK001/CLK001.h"

#elif ((__TARGET_DEVICE__ == XMC11) || (__TARGET_DEVICE__ == XMC12) || \
                                            (__TARGET_DEVICE__ == XMC13))
#include "../../inc/CLK002/CLK002.h"
#endif

/*****************************************************************************
              DUMMY DEFINITIONS OF DEBUG LOG MACROS
*****************************************************************************/
/* These definitions are included here to avoid compilation errors,
 since the DBG002 app is not part of the project. All the macros are defined
 as empty */
#ifndef _DBG002_H_

#define DBG002_MESSAGEID_LITERAL
#define DBG002_RegisterCallBack(A,B,C)
#define DBG002_I(e) 
#define DBG002_IG(e,g) 
#define DBG002_IH(e,h) 
#define DBG002_IP(e,p) 
#define DBG002_IGH(e,g,h) 
#define DBG002_IGP(e,g,p) 
#define DBG002_IHP(e,h,p) 
#define DBG002_IGHP(e,g,h,p) 
#define DBG002_N(e) 
#define DBG002_NG(e,g) 
#define DBG002_NH(e,h) 
#define DBG002_NP(e,p) 
#define DBG002_NGH(e,g,h) 
#define DBG002_NGP(e,g,p) 
#define DBG002_NHP(e,h,p) 
#define DBG002_NGHP(e,g,h,p) 
#define DBG002_ID(e) 
#define DBG002_IS(e) 
#define DBG002_ISG(e,g) 
#define DBG002_SAFETY_CRITICAL(groupid,messageid,length,value)
#define DBG002_CRITICAL(groupid,messageid,length,value)
#define DBG002_ERROR(groupid,messageid,length,value)
#define DBG002_WARNING(groupid,messageid,length,value)
#define DBG002_INFO(groupid,messageid,length,value)
#define DBG002_TRACE(groupid,messageid,length,value)
#define DBG002_FUNCTION_ENTRY(GID, Status) 
#define DBG002_FUNCTION_EXIT(GID, Status) 

#endif/* End of definitions of dummy Debug Log macros*/                  

/*******************************************************************************
** PRIVATE MACRO DEFINITIONS:
*******************************************************************************/
/**
 * @ingroup SYSTM002_constants
 * @{
 */

#define APP_GID DBG002_GID_SYSTM002
#define HW_TIMER_ADDITIONAL_CNT (1U)

/**
 * @}
 */
/*******************************************************************************
** PRIVATE TYPE DEFINITIONS:
*******************************************************************************/

/*******************************************************************************
** PRIVATE FUNCTION DECLARATIONS:
*******************************************************************************/
/*
 * @brief      This function is called to insert a timer into the timer list.  
 *        
 * @param[in]  Index Timer ID
 * @return     none
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM002_lInsertTimerList (uint32_t Index);


/*
 * @brief      This function is called to remove a timer from the timer list. 
 *              
 * @param[in]  Index Timer ID
 * @return     none
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM002_lRemoveTimerList(uint32_t Index);

/*
 * @brief      Handler function called from Systick event handler. 
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
static void  SYSTM002_lTimerHandler (void);

/*
 * @brief      Systick handler
 *              
 * @return     void 
 *      
 * <b>Reentrant: NO </b><BR>
 * <b>Sync/Async:  Synchronous</b>
 *
 */
void  SysTick_Handler (void);

/*******************************************************************************
** GLOBAL CONSTANT DEFINITIONS:
*******************************************************************************/

/*******************************************************************************
** GLOBAL VARIABLE DEFINITIONS:
*******************************************************************************/  
/** Table which save timer control block. */
SYSTM002_TimerObject TimerTbl[SYSTM002_CFG_MAX_TMR];

/** The header of the Timer Control list. */
SYSTM002_TimerObject*  TimerList = NULL;

 /**   Timer ID Tracker  */
uint32_t TimerTracker = 0UL;

/** SysTick Counter */
uint32_t SysTickCount = 0UL;

/*******************************************************************************
** PRIVATE CONSTANT DEFINITIONS:
*******************************************************************************/

/*******************************************************************************
** FUNCTION LIKE MACRO DEFINITIONS:
*******************************************************************************/

/*******************************************************************************
** PRIVATE VARIABLES:
*******************************************************************************/

/*******************************************************************************
** PRIVATE FUNCTION DEFINITIONS:
*******************************************************************************/
/*
 * This function is called to insert a timer into the timer list.
 */
 
static void  SYSTM002_lInsertTimerList (uint32_t Index)
{
  SYSTM002_TimerObject* TmrObjPtr;
  volatile int32_t DeltaTicks;
  uint32_t TempTmrCnt;
   /* Get timer time */
  TempTmrCnt = TimerTbl[Index].TimerCount;
  /* Check if timer count is zero */
  /* <<<DD_SYSTM002_PRIV _API_1>>> */

  /* Check if Timer list is NULL */
  if(NULL == TimerList)
  {
      /* Set this as first Timer */
      TimerList = &TimerTbl[Index];
  }
  /* If not, find the correct place, and insert the specified timer */
  else
  {
    TmrObjPtr = TimerList;
    /* Get timer tick */
    DeltaTicks = (int32_t)TempTmrCnt;
    /* Find correct place for inserting the timer */
    while(NULL != TmrObjPtr)
    {
      /* Get timer Count Difference  */
      DeltaTicks -= (int32_t)TmrObjPtr->TimerCount;
      /* Is delta ticks<0? */
      if(DeltaTicks < 0)
      {
        /*  Check If head item */
        if(NULL != TmrObjPtr->TimerPrev)
        {
          /* If Insert to list */
          TmrObjPtr->TimerPrev->TimerNext = &TimerTbl[Index];
          TimerTbl[Index].TimerPrev = TmrObjPtr->TimerPrev;
          TimerTbl[Index].TimerNext = TmrObjPtr;
          TmrObjPtr->TimerPrev = &TimerTbl[Index];
        }
        else
        {
          /* Set Timer as first item */
          TimerTbl[Index].TimerNext = TimerList;
          TimerList->TimerPrev = &TimerTbl[Index];
          TimerList = &TimerTbl[Index];
        }
        TimerTbl[Index].TimerCount = \
                TimerTbl[Index].TimerNext->TimerCount + (uint32_t)DeltaTicks;
        TimerTbl[Index].TimerNext->TimerCount  -= TimerTbl[Index].TimerCount;
        break;
      }
      /* Is last item in list? */
      else
      {
        if((DeltaTicks >= 0) && (NULL == TmrObjPtr->TimerNext))
        {
          /* Yes, insert into */
          TimerTbl[Index].TimerPrev = TmrObjPtr;
          TmrObjPtr->TimerNext = &TimerTbl[Index];
          TimerTbl[Index].TimerCount = (uint32_t)DeltaTicks;
          break; /* misra's */
        }
        else
       	{
       	    /* for misra */
       	}
      }
      /* Get the next item in timer list    */
      TmrObjPtr = TmrObjPtr->TimerNext;
    }
  }
}

/*
 * This function is called to remove a timer from the timer list. 
 */
static void  SYSTM002_lRemoveTimerList(uint32_t Index)
{
  SYSTM002_TimerObject* TmrObjPtr;
  TmrObjPtr = &TimerTbl[Index];
  /* Check whether only one timer available */
  /* <<<DD_SYSTM002_PRIV _API_2>>> */
  if((NULL == TmrObjPtr->TimerPrev) && (NULL == TmrObjPtr->TimerNext ))
  {
    /* set timer list as NULL */ 
    TimerList = NULL;                 	
  }
   /* Check if the first item in timer list   */
  else if(NULL == TmrObjPtr->TimerPrev)     
  {   
    /* Remove timer from list, and reset timer list */
    TimerList  = TmrObjPtr->TimerNext;
    TimerList->TimerPrev = NULL;
    TmrObjPtr->TimerNext->TimerCount += TmrObjPtr->TimerCount;
    TmrObjPtr->TimerNext    = NULL;  
  }
  /* Check if the last item in timer list */
  else if(NULL == TmrObjPtr->TimerNext)      
  {
    /* Remove timer from list */
    TmrObjPtr->TimerPrev->TimerNext = NULL;	
    TmrObjPtr->TimerPrev = NULL;
  }
  else                       
  {
    /* Remove timer from list */
    TmrObjPtr->TimerPrev->TimerNext  =  TmrObjPtr->TimerNext;
    TmrObjPtr->TimerNext->TimerPrev  =  TmrObjPtr->TimerPrev;
    TmrObjPtr->TimerNext->TimerCount  += TmrObjPtr->TimerCount;
    TmrObjPtr->TimerNext = NULL;
    TmrObjPtr->TimerPrev = NULL;
  }
}

/*
 * Handler function called from Systick event handler. 
 */
static void  SYSTM002_lTimerHandler (void)
{
  SYSTM002_TimerObject* TmrObjPtr;
   /* Get first item of timer list */
  TmrObjPtr = TimerList;         
  /* <<<DD_SYSTM002_PRIV _API_3>>> */  
  while((NULL != TmrObjPtr) && (0UL == TmrObjPtr->TimerCount ))
  {	
    /* Check whether timer is a one shot timer */
    if(SYSTM002_ONE_SHOT == TmrObjPtr->TimerType)
    {
      /* Yes, remove this timer from timer list */
      SYSTM002_lRemoveTimerList(TmrObjPtr->TimerID);
      /* Set timer status as SYSTM002_STATE_STOPPED */
      TmrObjPtr->TimerState = SYSTM002_STATE_STOPPED;
      /* Call timer callback function */
      (TmrObjPtr->TimerCallBack)(TmrObjPtr->ParamToCallBack);
    }
    /* Check whether timer is SYSTM002_PERIODIC */
    else if(SYSTM002_PERIODIC == TmrObjPtr->TimerType)
    {
      /* Yes, remove this timer from timer list */
      SYSTM002_lRemoveTimerList(TmrObjPtr->TimerID);
      /* Reset timer tick */
      TmrObjPtr->TimerCount = TmrObjPtr->TimerReload;
        /* Insert timer into timer list */
      SYSTM002_lInsertTimerList(TmrObjPtr->TimerID);
      /* Call timer callback function */
      (TmrObjPtr->TimerCallBack)(TmrObjPtr->ParamToCallBack);
    }
    else
    {
      break;
    }
    /* Get first item of timer list */
    TmrObjPtr = TimerList;
  }
}

/*
 *  SysTick Event Handler 
 */
void  SysTick_Handler(void)
{ 
  SYSTM002_TimerObject* TmrObjPtr;
  TmrObjPtr = TimerList;
  /* <<<DD_SYSTM002_PRIV _API_4>>> */
  SysTickCount++;

  if(NULL == TmrObjPtr)
  {
    /* Not supposed to be here */
    ;
  }
  else
  {
    if(TmrObjPtr->TimerCount > 1UL)
    {
      TmrObjPtr->TimerCount--;
    }
    else
    { 
      TmrObjPtr->TimerCount = 0UL;
      SYSTM002_lTimerHandler();
    }
  }
}

/*******************************************************************************
** PUBLIC FUNCTION DEFINITIONS:
*******************************************************************************/ 
/** @ingroup Simple_System_Timer_App PublicFunc
 * @{
 */
 
/*
 *  Initialization function which initializes the App internal data
 *  structures to default values. 
 */
void  SYSTM002_Init( void)
{
  volatile uint32_t Timer_Status = SYSTM002_TIMER_CONFIGURATION_SUCCESS;
  /* <<<DD_SYSTM002 _API_1>>> */
  /** Initialize the header of the list */
  TimerList = NULL;
  /**   Initialize timer tracker  */
  Timer_Status = SysTick_Config((uint32_t)(SYSTM002_SysTickMicroSec( \
                                                  SYSTM002_SYSTICK_INTERVAL))); 
                                                
  if(SYSTM002_TIMER_CONFIGURATION_FAILURE == Timer_Status)
  {
    DBG002_INFO(APP_GID, DBG002_MESSAGEID_LITERAL, \
         sizeof("SYSTM002_Init: Timer reload value out of range"), \
                     "SYSTM002_Init: Timer reload value out of range");
  }
  else
  {
 /**  setting of Priority and subpriority value for XMC4000 devices */
#if ((__TARGET_DEVICE__ == XMC44) || (__TARGET_DEVICE__ == XMC42) || \
                (__TARGET_DEVICE__ == XMC41) || (__TARGET_DEVICE__ == XMC45))
    NVIC_SetPriority(SysTick_IRQn, NVIC_EncodePriority( \
    NVIC_GetPriorityGrouping(),SYSTM002_PRIORITY,SYSTM002_SUBPRIORITY)); 

    /**  setting of Priority value for XMC1000 devices */
#elif ((__TARGET_DEVICE__ == XMC11) || (__TARGET_DEVICE__ == XMC12) \
                                         || (__TARGET_DEVICE__ == XMC13)) 
  NVIC_SetPriority(SysTick_IRQn, SYSTM002_PRIORITY);
#endif      
    TimerTracker = 0UL;
  }
  
}

/*
 *  Interface for creating a new software Timer instance.
 *  Note: Because of invocation of SYSTM002_Init() : Timer reload value 
 *  programmed, Hardware System Timer started. Software Timer will be created
 *  using SYSTM002_CreateTimer(). Due to time at which SW timer creation asked
 *  by user will not be in sync with HW timer, the count value used below with
 *  SW Timer, will not create starting/initial period same as expected value.
 *  To SW timer period (Initial one) equal to more than expected, it is decided
 *  to add one extra count(HW_TIMER_ADDITIONAL_CNT) with Software timer.
 *
 *  Impact: Impact of this additional count(HW_TIMER_ADDITIONAL_CNT) is,
 *  First SW Timer period is always equal to or more than expected/configured. 
 */
handle_t SYSTM002_CreateTimer
(
  uint32_t Period,
  SYSTM002_TimerType TimerType, 
  SYSTM002_TimerCallBackPtr TimerCallBack, 
  void  * pCallBackArgPtr
)
{
  uint32_t TimerID = 0UL;
  uint32_t Count = 0UL;
  uint32_t Error = 0UL;
  uint32_t PeriodRatio = 0U;

  /* Check for input parameter */
    if((SYSTM002_ONE_SHOT != TimerType) && (SYSTM002_PERIODIC != TimerType))
    {
      Error = SYSTM002_TIMER_CREATION_FAILURE;
      DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
    }
    else
    {
      /* for misra */
    }
    
    if(Period < (uint32_t)SYSTM002_SYSTICK_INTERVAL)
    {
      Error = SYSTM002_TIMER_CREATION_FAILURE;
      DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
    }
    else
    {
      /* for misra */
    }
    
    if(0UL == Period)          /* Timer with '0' time is not allowed. */
    {
      Error = SYSTM002_TIMER_CREATION_FAILURE;
      DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
    }
    else
    {
      /* for misra */
    }
    
    if(NULL == TimerCallBack)
    {
      Error = SYSTM002_TIMER_CREATION_FAILURE;
      DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
      
    }
    else
    {
      /* for misra */
    }
    
    if (!Error)	
    {
       for(Count = 0UL; Count < SYSTM002_CFG_MAX_TMR; Count++)
       {
           /* Check for free timer ID */
           if(0UL == (TimerTracker & (SYSTM002_BIT_SET << Count)))
           {
               /* If yes,assign ID to this timer      */
               TimerTracker |= (SYSTM002_BIT_SET << Count);
               /* Initialize the timer as per input values */
               TimerTbl[Count].TimerID     = Count;
               TimerTbl[Count].TimerType   = TimerType;
               TimerTbl[Count].TimerState  = SYSTM002_STATE_STOPPED;
               PeriodRatio = SYSTM002_PeriodRatioSysClockInterval(Period);
			   
               TimerTbl[Count].TimerCount  = \
                               (PeriodRatio + HW_TIMER_ADDITIONAL_CNT);
               TimerTbl[Count].TimerReload  = PeriodRatio;
			   
               TimerTbl[Count].TimerCallBack = TimerCallBack;
               TimerTbl[Count].ParamToCallBack = pCallBackArgPtr;
               TimerTbl[Count].TimerPrev   = NULL;
               TimerTbl[Count].TimerNext   = NULL;
               TimerID = Count + SYSTM002_INCREMENT_COUNT;
               break;
            }
           else
           {
             /* for misra */
           }
        }
    }
    else
    {
      /* for misra */
    }

  return (handle_t)TimerID;
}  

/*
 *  Interface to start the software timer .
 */
status_t SYSTM002_StartTimer(handle_t  Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;

  /* Check validity of parameter */
  if(Handle > SYSTM002_CFG_MAX_TMR)
  {
    Error = (status_t)SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }
  if(0UL == (TimerTracker & (SYSTM002_BIT_SET << (Handle - 1UL))))
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }
  /* Any timer with time '0', can't start again. */
  if(0UL == TimerTbl[Handle - 1U].TimerCount)
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }
  
  if((status_t)DAVEApp_SUCCESS == Error)
  {
    /* Check if timer is running */
    if(SYSTM002_STATE_RUNNING != TimerTbl[(Handle - 1U)].TimerState)
    {
      /* set timer status as SYSTM002_STATE_RUNNING */
      TimerTbl[(Handle - 1U)].TimerState = SYSTM002_STATE_RUNNING;
      /* Insert this timer into timer list  */
      SYSTM002_lInsertTimerList((Handle - 1U));
    }
    else
    {
      /* for misra */
    }
  }
  else
  {
    /* for misra */
  }

  return Error;
}


/*
 *  Interface to stop the software timer.
 */
status_t SYSTM002_StopTimer(handle_t Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;

  /* Check validity of parameter        */
  if(Handle > SYSTM002_CFG_MAX_TMR)
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }
  if(0UL == (TimerTracker & (SYSTM002_BIT_SET << (Handle - 1UL))))
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }

  if((status_t)DAVEApp_SUCCESS == Error)
  {
    /* Check whether Timer is in Stop state */
    if(SYSTM002_STATE_STOPPED != TimerTbl[(Handle - 1U)].TimerState)
    {
      /* remove Timer from node list */
      SYSTM002_lRemoveTimerList((Handle - 1U));

      /* Set timer status as SYSTM002_STATE_STOPPED  */
      TimerTbl[(Handle - 1U)].TimerState = SYSTM002_STATE_STOPPED;
    }
    else
    {
      /* for misra */
    }
  }
  else
  {
    /* for misra */
  }

  return Error;
}

/*
 *  Function to delete the Timer instance.
 */
status_t SYSTM002_DeleteTimer(handle_t Handle) 
{
  status_t Error = (status_t )DAVEApp_SUCCESS;

  /* Check validity of parameter      */
  if(Handle > SYSTM002_CFG_MAX_TMR)
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
  /* for misra */
  }
  if(0UL == (TimerTracker & (SYSTM002_BIT_SET << (Handle - 1UL))))
  {
    Error = (status_t) SYSTM002_INVALID_HANDLE_ERROR;
    DBG002_ERROR(APP_GID, DBG002_MESSAGEID_LITERAL, sizeof(Error), &Error);
  }
  else
  {
    /* for misra */
  }

  if((status_t)DAVEApp_SUCCESS == Error)
  {
    /* Check if timer is running */
    if(SYSTM002_STATE_RUNNING == TimerTbl[(Handle - 1U)].TimerState)
    {
      /* Yes,remove this timer from timer list*/
      SYSTM002_lRemoveTimerList((Handle - 1U));
    }
    else
    {
     /* for misra */
    }

    /* Release resource that this timer hold */
    TimerTracker &=~(SYSTM002_BIT_SET << (Handle - 1UL));
  }
  else
  {
    /* for misra */
  }

  return Error;

}

/*
 *  Interface to get the current system time in microsecond.
 */
inline uint32_t  SYSTM002_GetTime(void)
{
  /* <<<DD_SYSTM002 _API_6>>> */
  return (SysTickCount * SYSTM002_SYSTICK_INTERVAL);
   
}

/**
 * @endcond
 */
/*CODE_BLOCK_END*/


