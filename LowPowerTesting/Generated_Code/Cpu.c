/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Cpu.c
**     Project     : LowPowerTesting
**     Processor   : MKL25Z128VLK4
**     Component   : MKL25Z128LK4
**     Version     : Component 01.025, Driver 01.04, CPU db: 3.00.000
**     Datasheet   : KL25P80M48SF0RM, Rev.3, Sep 2012
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-09-04, 10:56, # CodeGen: 32
**     Abstract    :
**
**     Settings    :
**
**     Contents    :
**         SetOperationMode  - LDD_TError Cpu_SetOperationMode(LDD_TDriverOperationMode OperationMode,...
**         GetLLSWakeUpFlags - uint32_t Cpu_GetLLSWakeUpFlags(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file Cpu.c
** @version 01.04
** @brief
**
*/         
/*!
**  @addtogroup Cpu_module Cpu module documentation
**  @{
*/         

/* MODULE Cpu. */

/* {Default RTOS Adapter} No RTOS includes */
#include "Bit1.h"
#include "DHT22Pin.h"
#include "DHT22Timer.h"
#include "TimerIntLdd1.h"
#include "TU1.h"
#include "TSL2561Timer.h"
#include "TimerIntLdd2.h"
#include "TU2.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Events.h"
#include "Cpu.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Global variables */
volatile uint8_t SR_reg;               /* Current value of the FAULTMASK register */
volatile uint8_t SR_lock = 0x00U;      /* Lock */


/*
** ===================================================================
**     Method      :  Cpu_GetLLSWakeUpFlags (component MKL25Z128LK4)
*/
/*!
**     @brief
**         This method returns the current status of the LLWU wake-up
**         flags indicating which wake-up source caused the MCU to exit
**         LLS or VLLSx low power mode.
**         The following predefined constants can be used to determine
**         the wake-up source:
**         LLWU_EXT_PIN0, ... LLWU_EXT_PIN15 - external pin 0 .. 15
**         caused the wake-up
**         LLWU_INT_MODULE0 .. LLWU_INT_MODULE7 - internal module 0..15
**         caused the wake-up.
**     @return
**                         - Returns the current status of the LLWU
**                           wake-up flags indicating which wake-up
**                           source caused the MCU to exit LLS or VLLSx
**                           low power mode.
*/
/* ===================================================================*/
uint32_t Cpu_GetLLSWakeUpFlags(void)
{
  uint32_t Flags;

  Flags = LLWU_F1;
  Flags |= (uint32_t)((uint32_t)LLWU_F2 << 8U);
  Flags |= (uint32_t)((uint32_t)LLWU_F3 << 16U);
  if ((LLWU_FILT1 & 0x80U) != 0x00U ) {
    Flags |= LLWU_FILTER1;
  }
  if ((LLWU_FILT2 & 0x80U) != 0x00U ) {
    Flags |= LLWU_FILTER2;
  }
  return Flags;
}

/*
** ===================================================================
**     Method      :  Cpu_Cpu_ivINT_PIT (component MKL25Z128LK4)
**
**     Description :
**         This ISR services the ivINT_PIT interrupt shared by several 
**         components.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_ivINT_PIT)
{
  TU1_Interrupt();                     /* Call the service routine */
  TU2_Interrupt();                     /* Call the service routine */
}

/*
** ===================================================================
**     Method      :  Cpu_INT_NMIInterrupt (component MKL25Z128LK4)
**
**     Description :
**         This ISR services the Non Maskable Interrupt interrupt.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_INT_NMIInterrupt)
{
  Cpu_OnNMIINT();
}

/*
** ===================================================================
**     Method      :  Cpu_Cpu_Interrupt (component MKL25Z128LK4)
**
**     Description :
**         This ISR services an unused interrupt/exception vector.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(Cpu_Interrupt)
{
  /* This code can be changed using the CPU component property "Build Options / Unhandled int code" */
  PE_DEBUGHALT();
}

/*
** ===================================================================
**     Method      :  Cpu_SetOperationMode (component MKL25Z128LK4)
*/
/*!
**     @brief
**         This method requests to change the component's operation
**         mode (RUN, WAIT, SLEEP, STOP). The target operation mode
**         will be entered immediately. 
**         See [Operation mode settings] for further details of the
**         operation modes mapping to low power modes of the cpu.
**     @param
**         OperationMode   - Requested driver
**                           operation mode
**     @param
**         ModeChangeCallback - Callback to
**                           notify the upper layer once a mode has been
**                           changed. Parameter is ignored, only for
**                           compatibility of API with other components.
**     @param
**         ModeChangeCallbackParamPtr 
**                           - Pointer to callback parameter to notify
**                           the upper layer once a mode has been
**                           changed. Parameter is ignored, only for
**                           compatibility of API with other components.
**     @return
**                         - Error code
**                           ERR_OK - OK
**                           ERR_PARAM_MODE - Invalid operation mode
*/
/* ===================================================================*/
LDD_TError Cpu_SetOperationMode(LDD_TDriverOperationMode OperationMode, LDD_TCallback ModeChangeCallback, LDD_TCallbackParam *ModeChangeCallbackParamPtr)
{
  (void) ModeChangeCallback;           /* Parameter is not used, suppress unused argument warning */
  (void) ModeChangeCallbackParamPtr;   /* Parameter is not used, suppress unused argument warning */
  switch (OperationMode) {
    case DOM_RUN:
      /* SCB_SCR: SLEEPDEEP=0,SLEEPONEXIT=0 */
      SCB_SCR &= (uint32_t)~(uint32_t)(
                  SCB_SCR_SLEEPDEEP_MASK |
                  SCB_SCR_SLEEPONEXIT_MASK
                 );
      break;
    case DOM_WAIT:
      /* SCB_SCR: SLEEPDEEP=0 */
      SCB_SCR &= (uint32_t)~(uint32_t)(SCB_SCR_SLEEPDEEP_MASK);
      /* SCB_SCR: SLEEPONEXIT=0 */
      SCB_SCR &= (uint32_t)~(uint32_t)(SCB_SCR_SLEEPONEXIT_MASK);
      PE_WFI();
      break;
    case DOM_SLEEP:
      /* SCB_SCR: SLEEPDEEP=1 */
      SCB_SCR |= SCB_SCR_SLEEPDEEP_MASK;
      /* SMC_STOPCTRL: PSTOPO=0,PORPO=0,??=0,??=0,VLLSM=0 */
      SMC_STOPCTRL = (SMC_STOPCTRL_PSTOPO(0x00) | SMC_STOPCTRL_VLLSM(0x00));
      /* SMC_PMCTRL: STOPM=0 */
      SMC_PMCTRL &= (uint8_t)~(uint8_t)(SMC_PMCTRL_STOPM(0x07));
      (void)(SMC_PMCTRL == 0U);        /* Dummy read of SMC_PMCTRL to ensure the register is written before enterring low power mode */
      /* SCB_SCR: SLEEPONEXIT=0 */
      SCB_SCR &= (uint32_t)~(uint32_t)(SCB_SCR_SLEEPONEXIT_MASK);
      PE_WFI();
      break;
    case DOM_STOP:
    /* Clear LLWU flags */
      /* LLWU_F1: WUF7=1,WUF6=1,WUF5=1,WUF4=1,WUF3=1,WUF2=1,WUF1=1,WUF0=1 */
      LLWU_F1 = LLWU_F1_WUF7_MASK |
                LLWU_F1_WUF6_MASK |
                LLWU_F1_WUF5_MASK |
                LLWU_F1_WUF4_MASK |
                LLWU_F1_WUF3_MASK |
                LLWU_F1_WUF2_MASK |
                LLWU_F1_WUF1_MASK |
                LLWU_F1_WUF0_MASK;
      /* LLWU_F2: WUF15=1,WUF14=1,WUF13=1,WUF12=1,WUF11=1,WUF10=1,WUF9=1,WUF8=1 */
      LLWU_F2 = LLWU_F2_WUF15_MASK |
                LLWU_F2_WUF14_MASK |
                LLWU_F2_WUF13_MASK |
                LLWU_F2_WUF12_MASK |
                LLWU_F2_WUF11_MASK |
                LLWU_F2_WUF10_MASK |
                LLWU_F2_WUF9_MASK |
                LLWU_F2_WUF8_MASK;
      /* LLWU_F3: MWUF7=1,MWUF6=1,MWUF5=1,MWUF4=1,MWUF3=1,MWUF2=1,MWUF1=1,MWUF0=1 */
      LLWU_F3 = LLWU_F3_MWUF7_MASK |
                LLWU_F3_MWUF6_MASK |
                LLWU_F3_MWUF5_MASK |
                LLWU_F3_MWUF4_MASK |
                LLWU_F3_MWUF3_MASK |
                LLWU_F3_MWUF2_MASK |
                LLWU_F3_MWUF1_MASK |
                LLWU_F3_MWUF0_MASK;
      /* LLWU_FILT1: FILTF=1 */
      LLWU_FILT1 |= LLWU_FILT1_FILTF_MASK;
      /* LLWU_FILT2: FILTF=1 */
      LLWU_FILT2 |= LLWU_FILT2_FILTF_MASK;
      /* SCB_SCR: SLEEPONEXIT=0 */
      SCB_SCR &= (uint32_t)~(uint32_t)(SCB_SCR_SLEEPONEXIT_MASK);
      /* SCB_SCR: SLEEPDEEP=1 */
      SCB_SCR |= SCB_SCR_SLEEPDEEP_MASK;
      /* SMC_PMCTRL: STOPM=4 */
      SMC_PMCTRL = (uint8_t)((SMC_PMCTRL & (uint8_t)~(uint8_t)(
                    SMC_PMCTRL_STOPM(0x03)
                   )) | (uint8_t)(
                    SMC_PMCTRL_STOPM(0x04)
                   ));
      /* SMC_STOPCTRL: PSTOPO=0,PORPO=0,??=0,??=0,VLLSM=0 */
      SMC_STOPCTRL = (SMC_STOPCTRL_PSTOPO(0x00) | SMC_STOPCTRL_VLLSM(0x00));
      (void)(SMC_PMCTRL == 0U);        /* Dummy read of SMC_PMCTRL to ensure the register is written before enterring low power mode */
      PE_WFI();
      break;
    default:
      return ERR_PARAM_MODE;
  }
  return ERR_OK;
}


/*** !!! Here you can place your own code using property "User data declarations" on the build options tab. !!! ***/

/*lint -esym(765,__init_hardware) Disable MISRA rule (8.10) checking for symbols (__init_hardware). The function is linked to the EWL library */
/*lint -esym(765,Cpu_Interrupt) Disable MISRA rule (8.10) checking for symbols (Cpu_Interrupt). */
void __init_hardware(void)
{

  /*** !!! Here you can place your own code before PE initialization using property "User code before PE initialization" on the build options tab. !!! ***/

  /*** ### MKL25Z128VLK4 "Cpu" init code ... ***/
  /*** PE initialization code after reset ***/
  SCB_VTOR = (uint32_t)(&__vect_table); /* Set the interrupt vector table position */
  /* Disable the WDOG module */
  /* SIM_COPC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COPT=0,COPCLKS=0,COPW=0 */
  SIM_COPC = SIM_COPC_COPT(0x00);

  /* System clock initialization */
  /* SIM_CLKDIV1: OUTDIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,OUTDIV4=3,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0x00) | SIM_CLKDIV1_OUTDIV4(0x03)); /* Set the system prescalers to safe value */
  /* SIM_SCGC5: PORTD=1,PORTB=1,PORTA=1 */
  SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK |
               SIM_SCGC5_PORTB_MASK |
               SIM_SCGC5_PORTA_MASK;   /* Enable clock gate for ports to enable pin routing */
  if ((PMC_REGSC & PMC_REGSC_ACKISO_MASK) != 0x0U) {
    /* PMC_REGSC: ACKISO=1 */
    PMC_REGSC |= PMC_REGSC_ACKISO_MASK; /* Release IO pads after wakeup from VLLS mode. */
  }
  /* SIM_CLKDIV1: OUTDIV1=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,OUTDIV4=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  SIM_CLKDIV1 = (SIM_CLKDIV1_OUTDIV1(0x00) | SIM_CLKDIV1_OUTDIV4(0x00)); /* Update system prescalers */
  /* SIM_SOPT2: PLLFLLSEL=0 */
  SIM_SOPT2 &= (uint32_t)~(uint32_t)(SIM_SOPT2_PLLFLLSEL_MASK); /* Select FLL as a clock source for various peripherals */
  /* SIM_SOPT1: OSC32KSEL=3 */
  SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(0x03); /* LPO 1kHz oscillator drives 32 kHz clock for various peripherals */
  /* SIM_SOPT2: TPMSRC=1 */
  SIM_SOPT2 = (uint32_t)((SIM_SOPT2 & (uint32_t)~(uint32_t)(
               SIM_SOPT2_TPMSRC(0x02)
              )) | (uint32_t)(
               SIM_SOPT2_TPMSRC(0x01)
              ));                      /* Set the TPM clock */
  /* Switch to FEI Mode */
  /* MCG_C1: CLKS=0,FRDIV=0,IREFS=1,IRCLKEN=1,IREFSTEN=0 */
  MCG_C1 = MCG_C1_CLKS(0x00) |
           MCG_C1_FRDIV(0x00) |
           MCG_C1_IREFS_MASK |
           MCG_C1_IRCLKEN_MASK;
  /* MCG_C2: LOCRE0=0,??=0,RANGE0=0,HGO0=0,EREFS0=0,LP=0,IRCS=0 */
  MCG_C2 = MCG_C2_RANGE0(0x00);
  /* MCG_C4: DMX32=0,DRST_DRS=0 */
  MCG_C4 &= (uint8_t)~(uint8_t)((MCG_C4_DMX32_MASK | MCG_C4_DRST_DRS(0x03)));
  /* OSC0_CR: ERCLKEN=1,??=0,EREFSTEN=0,??=0,SC2P=0,SC4P=0,SC8P=0,SC16P=0 */
  OSC0_CR = OSC_CR_ERCLKEN_MASK;
  /* MCG_C5: ??=0,PLLCLKEN0=0,PLLSTEN0=0,PRDIV0=0 */
  MCG_C5 = MCG_C5_PRDIV0(0x00);
  /* MCG_C6: LOLIE0=0,PLLS=0,CME0=0,VDIV0=0 */
  MCG_C6 = MCG_C6_VDIV0(0x00);
  while((MCG_S & MCG_S_IREFST_MASK) == 0x00U) { /* Check that the source of the FLL reference clock is the internal reference clock. */
  }
  while((MCG_S & 0x0CU) != 0x00U) {    /* Wait until output of the FLL is selected */
  }
  /*** End of PE initialization code after reset ***/

  /*** !!! Here you can place your own code after PE initialization using property "User code after PE initialization" on the build options tab. !!! ***/

}



/*
** ===================================================================
**     Method      :  PE_low_level_init (component MKL25Z128LK4)
**
**     Description :
**         Initializes beans and provides common register initialization. 
**         The method is called automatically as a part of the 
**         application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_low_level_init(void)
{
  #ifdef PEX_RTOS_INIT
    PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
      /* Initialization of the SIM module */
  /* PORTA_PCR4: ISF=0,MUX=7 */
  PORTA_PCR4 = (uint32_t)((PORTA_PCR4 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK
               )) | (uint32_t)(
                PORT_PCR_MUX(0x07)
               ));
        /* Initialization of the RCM module */
  /* RCM_RPFW: RSTFLTSEL=0 */
  RCM_RPFW &= (uint8_t)~(uint8_t)(RCM_RPFW_RSTFLTSEL(0x1F));
  /* RCM_RPFC: RSTFLTSS=0,RSTFLTSRW=0 */
  RCM_RPFC &= (uint8_t)~(uint8_t)(
               RCM_RPFC_RSTFLTSS_MASK |
               RCM_RPFC_RSTFLTSRW(0x03)
              );
        /* Initialization of the FTFL_FlashConfig module */
      /* Initialization of the PMC module */
  /* PMC_LVDSC1: LVDACK=1,LVDIE=0,LVDRE=1,LVDV=0 */
  PMC_LVDSC1 = (uint8_t)((PMC_LVDSC1 & (uint8_t)~(uint8_t)(
                PMC_LVDSC1_LVDIE_MASK |
                PMC_LVDSC1_LVDV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC1_LVDACK_MASK |
                PMC_LVDSC1_LVDRE_MASK
               ));
  /* PMC_LVDSC2: LVWACK=1,LVWIE=0,LVWV=0 */
  PMC_LVDSC2 = (uint8_t)((PMC_LVDSC2 & (uint8_t)~(uint8_t)(
                PMC_LVDSC2_LVWIE_MASK |
                PMC_LVDSC2_LVWV(0x03)
               )) | (uint8_t)(
                PMC_LVDSC2_LVWACK_MASK
               ));
  /* PMC_REGSC: BGEN=0,ACKISO=0,BGBE=0 */
  PMC_REGSC &= (uint8_t)~(uint8_t)(
                PMC_REGSC_BGEN_MASK |
                PMC_REGSC_ACKISO_MASK |
                PMC_REGSC_BGBE_MASK
               );
        /* Initialization of the LLWU module */
  /* LLWU_PE2: WUPE7=0,WUPE6=0,WUPE5=0 */
  LLWU_PE2 &= (uint8_t)~(uint8_t)(
               LLWU_PE2_WUPE7(0x03) |
               LLWU_PE2_WUPE6(0x03) |
               LLWU_PE2_WUPE5(0x03)
              );
  /* LLWU_PE3: WUPE10=0,WUPE9=0,WUPE8=0 */
  LLWU_PE3 &= (uint8_t)~(uint8_t)(
               LLWU_PE3_WUPE10(0x03) |
               LLWU_PE3_WUPE9(0x03) |
               LLWU_PE3_WUPE8(0x03)
              );
  /* LLWU_PE4: WUPE15=0,WUPE14=0 */
  LLWU_PE4 &= (uint8_t)~(uint8_t)(
               LLWU_PE4_WUPE15(0x03) |
               LLWU_PE4_WUPE14(0x03)
              );
  /* LLWU_ME: WUME7=0,WUME5=0,WUME4=0,WUME1=0,WUME0=0 */
  LLWU_ME &= (uint8_t)~(uint8_t)(
              LLWU_ME_WUME7_MASK |
              LLWU_ME_WUME5_MASK |
              LLWU_ME_WUME4_MASK |
              LLWU_ME_WUME1_MASK |
              LLWU_ME_WUME0_MASK
             );
  /* LLWU_FILT1: FILTF=1,FILTE=0,??=0,FILTSEL=0 */
  LLWU_FILT1 = LLWU_FILT1_FILTF_MASK |
               LLWU_FILT1_FILTE(0x00) |
               LLWU_FILT1_FILTSEL(0x00);
  /* LLWU_FILT2: FILTF=1,FILTE=0,??=0,FILTSEL=0 */
  LLWU_FILT2 = LLWU_FILT2_FILTF_MASK |
               LLWU_FILT2_FILTE(0x00) |
               LLWU_FILT2_FILTSEL(0x00);
  /* SMC_PMPROT: ??=0,??=0,AVLP=1,??=0,ALLS=1,??=0,AVLLS=1,??=0 */
  SMC_PMPROT = SMC_PMPROT_AVLP_MASK |
               SMC_PMPROT_ALLS_MASK |
               SMC_PMPROT_AVLLS_MASK;  /* Setup Power mode protection register */
  /* Common initialization of the CPU registers */
  /* PORTA_PCR20: ISF=0,MUX=7 */
  PORTA_PCR20 = (uint32_t)((PORTA_PCR20 & (uint32_t)~(uint32_t)(
                 PORT_PCR_ISF_MASK
                )) | (uint32_t)(
                 PORT_PCR_MUX(0x07)
                ));
  /* NVIC_IPR1: PRI_7=0,PRI_6=0 */
  NVIC_IPR1 &= (uint32_t)~(uint32_t)(
                NVIC_IP_PRI_7(0xFF) |
                NVIC_IP_PRI_6(0xFF)
  );
  /* ### BitIO_LDD "Bit1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)Bit1_Init(NULL);
  /* ### TimerInt_LDD "TimerIntLdd1" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)TimerIntLdd1_Init(NULL);
  /* ### TimerInt "DHT22Timer" init code ... */
  /* ### TimerInt_LDD "TimerIntLdd2" component auto initialization. Auto initialization feature can be disabled by component property "Auto initialization". */
  (void)TimerIntLdd2_Init(NULL);
  /* ### TimerInt "TSL2561Timer" init code ... */
  __EI();
}
  /* Flash configuration field */
  __attribute__ ((section (".cfmconfig"))) const uint8_t _cfm[0x10] = {
   /* NV_BACKKEY3: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY2: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY1: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY0: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY7: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY6: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY5: KEY=0xFF */
    0xFFU,
   /* NV_BACKKEY4: KEY=0xFF */
    0xFFU,
   /* NV_FPROT3: PROT=0xFF */
    0xFFU,
   /* NV_FPROT2: PROT=0xFF */
    0xFFU,
   /* NV_FPROT1: PROT=0xFF */
    0xFFU,
   /* NV_FPROT0: PROT=0xFF */
    0xFFU,
   /* NV_FSEC: KEYEN=1,MEEN=3,FSLACC=3,SEC=2 */
    0x7EU,
   /* NV_FOPT: ??=1,??=1,FAST_INIT=1,LPBOOT1=1,RESET_PIN_CFG=1,NMI_DIS=1,??=1,LPBOOT0=1 */
    0xFFU,
    0xFFU,
    0xFFU
  };

/* END Cpu. */

#ifdef __cplusplus
}  /* extern "C" */
#endif

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
