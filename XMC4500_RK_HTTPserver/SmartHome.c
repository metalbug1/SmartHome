/*********************************************************************/
/* Author         Date            Description						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    30/01/2016    Initial version						 */
/*-------------------------------------------------------------------*/
/* Alina&Mihai    31/01/2016    Added processingData functions		 */
/*********************************************************************/


/** Inclusion of header file */
#include <DAVE3.h>
#include "netconf.h"
#include "lwip/err.h"
#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/tcp.h"
#include "lwip/netif.h"
#include "./Dave/Generated/src/WEBSERVER001/HTTPServer/httpd.h"

#include "SmartHome_Types.h"
#include "DataQueue.h"
#include "DataProcessing.h"
#include "WebServerFunctions.h"

/**
 * @brief This function is to initialize the VADC peripheral to continuous conversion with background source\n
 * Channel 1 in group 0 takes part in the scan sequence. The result is sent to RESREG[0]\n
 * @param[in]   none \n
 * @return none\n
 *
 * <b>Reentrancy:  no</b><BR>
 *
 */
void ADC0_Init(void) {
	SCU_RESET->PRCLR0 |= ((1 << SCU_RESET_PRSET0_VADCRS_Pos)
			& SCU_RESET_PRSET0_VADCRS_Msk);
	// De-assert reset: VADC Reset Clear Reset Clear = 1

	//Global ADC Initialization

	VADC->CLC = ((0 << VADC_CLC_DISR_Pos) & VADC_CLC_DISR_Msk) |
	// DISR = 0: Module Disable Request Bit
	// 0B On request: enable the module clock
			((0 << VADC_CLC_DISS_Pos) & VADC_CLC_DISS_Msk) |
			// DISS = 0: Module Disable Status Bit
			// 0B Module clock is enabled
			((0 << VADC_CLC_EDIS_Pos) & VADC_CLC_EDIS_Msk);
	// EDIS = 0: Sleep Mode Enable Control
	// 0B Sleep mode request is enabled and functional
	// Wait for module clock enabled
	while (VADC->CLC != 0)
		; // DISS: Module Disable Status Bit
		  //  0B Module clock is enabled

	VADC->GLOBCFG = ((6 << VADC_GLOBCFG_DIVA_Pos) & VADC_GLOBCFG_DIVA_Msk) |
	// DIVA = 6: Divider Factor for the Analog Internal Clock
	// fADCI = fADC / (DIVA + 1) = fADC / 7
			((1 << VADC_GLOBCFG_DIVWC_Pos) & VADC_GLOBCFG_DIVWC_Msk);
	// DIVWC = 1: Write Control for Divider Parameters
	// Bitfields DIVA, DCMSB, DIVD can be written

	//Arbitration
	VADC_G0->ARBCFG =
			((VADC_G0->ARBCFG
					& ~(VADC_G_ARBCFG_ANONC_Msk | VADC_G_ARBCFG_ARBRND_Msk
							| VADC_G_ARBCFG_ARBM_Msk)) |
			// Clear relevant bits
					(((3 << VADC_G_ARBCFG_ANONC_Pos) & VADC_G_ARBCFG_ANONC_Msk)
							|
							// ANONS = 11B: Analog Converter Control: Normal Operation
							//  The converter is active, conversions are started immediately.
							//  Requires no wakeup time.
							((0 << VADC_G_ARBCFG_ARBRND_Pos)
									& VADC_G_ARBCFG_ARBRND_Msk) |
							// ARBRND = 00B: Arbitration Round Length
							//  00B: 4 arbitration slots per round (tARB = 4 / fADCD)
							((0 << VADC_G_ARBCFG_ARBM_Pos)
									& VADC_G_ARBCFG_ARBM_Msk)));
	// ARBM = 0B: Arbitration Mode: The arbiter runs permanently

	VADC_G0->ARBPR = ((VADC_G0->ARBPR
			& ~(VADC_G_ARBPR_ASEN2_Msk | VADC_G_ARBPR_PRIO0_Msk)) |
	// clear relevant bits
			(((1 << VADC_G_ARBPR_PRIO0_Pos) & VADC_G_ARBPR_PRIO0_Msk) |
			// PRIO0 = 1: Priority of Request Source x (x = 0)
			//  Arbitration priority of request source x (in slot x)
					((1 << VADC_G_ARBPR_ASEN2_Pos) & VADC_G_ARBPR_ASEN2_Msk)));
	// ASEN2 = 1: Arbitration Slot 2 Enable

	//Conversion result storage
	VADC_G0->CHCTR[1] = ((0x1 << VADC_G_CHCTR_RESREG_Pos)
			& VADC_G_CHCTR_RESREG_Msk);
	// Channel 1 is directed to RESREG1
	//  0001B Store result in group result register GxRES1
	//  = VADC_G0->RES[1]

	//BACKGROUND SOURCE
	VADC->BRSSEL[0] = ((1 << 1) & VADC_BRSSEL_CHSELG_Msk);
	// CHSELG1 = 1: Channel Selection Group 0: Channel 1
	//  1B This channel is part of the scan sequence

	VADC->BRSCTRL = ((0 << VADC_BRSCTRL_XTSEL_Pos) & VADC_BRSCTRL_XTSEL_Msk) |
	// XTSEL = 0: External Trigger Input Selection
	//   not used: see XTMODE
			((0 << VADC_BRSCTRL_XTMODE_Pos) & VADC_BRSCTRL_XTMODE_Msk) |
			// XTMODE = 0: Trigger Operating Mode: No external trigger
			((1 << VADC_BRSCTRL_XTWC_Pos) & VADC_BRSCTRL_XTWC_Msk) |
			// XTWC = 1: Write Control for Trigger Configuration
			//  Bitfields XTMODE and XTSEL can be written
			((0 << VADC_BRSCTRL_GTSEL_Pos) & VADC_BRSCTRL_GTSEL_Msk) |
			// GTSEL = 0: Gate Input Selection
			((1 << VADC_BRSCTRL_GTWC_Pos) & VADC_BRSCTRL_GTWC_Msk);
	// GTWC = 1: Write Control for Gate Configuration
	//  Bitfield GTSEL can be written

	VADC->BRSMR = ((1 << VADC_BRSMR_ENGT_Pos) & VADC_BRSMR_ENGT_Msk) |
	// ENGT = 1: Enable Gate: 01B Conversion requests are
	//  issued if at least one pending bit is set
			((0 << VADC_BRSMR_ENTR_Pos) & VADC_BRSMR_ENTR_Msk) |
			// ENTR = 0: Enable External Trigger: 0B External trigger disabled
			((0 << VADC_BRSMR_ENSI_Pos) & VADC_BRSMR_ENSI_Msk) |
			// ENSI = 0: Enable Source Interrupt: 0B No request source interrupt
			((1 << VADC_BRSMR_SCAN_Pos) & VADC_BRSMR_SCAN_Msk) |
			// SCAN = 1: Autoscan Enable: 1B Autoscan functionality enabled:
			//  a request source event automatically generates a load event
			((0 << VADC_BRSMR_LDM_Pos) & VADC_BRSMR_LDM_Msk) |
			// LDM = 0: Autoscan Source Load Event Mode:
			//  0B Overwrite mode: Copy all bits from the select registers to the
			//  pending registers upon a load event
			((1 << VADC_BRSMR_LDEV_Pos) & VADC_BRSMR_LDEV_Msk);
	// LDEV = 1: Generate Load Event: 1B A load event is generated
	//  it is important to have a load event in initialization!
	//  after that autoscan takes control
}


int main(void)
{
	struct tcp_pcb *mypcb;
	uint8_t data[] = {1,2,3};

	float tensiune = 50;
	float rezistenta = 50;
	float temperatura = 50;
	uint16_t adc_result;


	DAVE_Init();			// Initialization of DAVE Apps

    lwIPStack_init();
    http_CGI_init();
    http_SSI_init();

    Queue_Init(&receivedDataQueue);

	ADC0_Init();
	while(1)
	{
		adc_result = VADC_G0->RES[1];
		tensiune = (adc_result * 3300) / 4096;
		rezistenta = tensiune * 1000/(3300 - tensiune);
		temperatura = (uint8_t)((0.1272 * rezistenta - 103.1) * 10);
		temperatura/=10;

		ProcessReceivedData();
	   /* mypcb = tcp_new();
	    tcp_bind(mypcb, IP_ADDR_ANY, 80);
		tcp_write(mypcb, data, 3, TCP_WRITE_FLAG_COPY);*/

	}
	return 0;
}
