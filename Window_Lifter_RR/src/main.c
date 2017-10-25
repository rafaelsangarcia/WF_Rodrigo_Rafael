//TESTED
//#include "MAL/GPIO_init.h"
//#include "HAL/Win_Mov.h"
#include "APP/Up_Down.h"


extern int switch_flag;
extern int lpit0_ch0_flag_counter;
extern int lpit0_ch1_flag_counter;

//volatile int exit_code = 0;
// int lpit0_ch0_flag_counter = 0; /* LPIT0 timeout counter */


int main(void)
{
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
#ifdef PEX_RTOS_INIT
	PEX_RTOS_INIT();                   /* Initialization of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of Processor Expert internal initialization.                    ***/

	//init_primary_function();
	WDOG_disable();
	PORT_init(); /* Configure ports */
	SOSC_init_8MHz(); /* Initialize system oscillator for 8 MHz xtal */
	SPLL_init_160MHz(); /* Initialize sysclk to 160 MHz with 8 MHz SOSC */
	NormalRUNmode_80MHz(); /* Init clocks: 80 MHz sysclk & core, 40 MHz bus, 20 MHz flash */
	LPIT0_init(); /* Initialize PIT0 for 1 second timeout */

	lpit0_ch0_flag_counter++; /* Increment LPIT0 timeout counter */
	clear_GPIO(); //clear PORTS


	for (;;) {
	/*	PTD->PSOR |= 1<<0;//Blue led off
		PTD->PSOR |= 1<<16;//Green led */
		if(Push_UpButton() == 1){
			timer();
			if(validation_10ms() == 1){
				if( Push_UpButton() == 0 ){ //up_off
					if(validation_500ms() == 0){
						while(switch_flag < 9){
							Manual_up();
						}
					}
				}
				else{
					if(validation_500ms() == 1){
							Manual_up();
					}
				}
			}
		}
		else if(Push_DownButton() == 1){
			timer();
			if(validation_10ms() == 1){
				if( Push_DownButton() == 0 ){ //up_off
					if(validation_500ms() == 0){
						while(switch_flag >=0){
							Manual_down();
						}
					}
				}
				else{
					if(validation_500ms() == 1){
							Manual_down();
					}
				}
			}
		}
		else {
			PTD->PSOR |= 1<<0;//Blue led off
			PTD->PSOR |= 1<<16;//Green led
			lpit0_ch1_flag_counter = 0;
		}
	}
}
//void PORT_init (void) {/*Initializing the PORTS*/
//	PCC-> PCCn[PCC_PORTD_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
//	PCC-> PCCn[PCC_PORTC_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
//	PCC-> PCCn[PCC_PORTB_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
//	PCC-> PCCn[PCC_PORTE_INDEX] = PCC_PCCn_CGC_MASK; /* Enable clock for PORT D */
//
//	PTD->PDDR |= 1<<0; /* Port D0: Data Direction= output */
//	PTD->PDDR |= 1<<15; /* Port D15: Data Direction= output */
//	PTD->PDDR |= 1<<16; /* Port D16: Data Direction= output */
//	PTC->PDDR |= 1<<7;/*Port C7: Data Direction= output*/
//	PTB->PDDR |= 1<<17;
//	PTB->PDDR |= 1<<14;
//	PTB->PDDR |= 1<<15;
//	PTB->PDDR |= 1<<16;
//	PTC->PDDR |= 1<<14;
//	PTC->PDDR |= 1<<3;
//	PTE->PDDR |= 1<<15;
//	PTE->PDDR |= 1<<16;
//	PTE->PDDR |= 1<<14;
//	PTC->PDDR &= ~(1<<12);/*PORT C12: Data Direction= input*/
//	PTC->PDDR &= ~(1<<13);/*PORT C13: Data Direction= input*/
//
//	PORTD->PCR[0]  = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to blue LED on EVB) */
//	PORTD->PCR[15] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to red LED on EVB) */
//	PORTD->PCR[16] = 0x00000100; /* Port D0: MUX = ALT1, GPIO (to green LED on EVB) */
//	PORTC->PCR[7] = 0x00000100;
//	PORTB->PCR[17] = 0x00000100;
//	PORTB->PCR[14] = 0x00000100;
//	PORTB->PCR[15] = 0x00000100;
//	PORTB->PCR[16] = 0x00000100;
//	PORTC->PCR[14] = 0x00000100;
//	PORTC->PCR[3] = 0x00000100;
//	PORTE->PCR[15] = 0x00000100;
//	PORTE->PCR[16] = 0x00000100;
//	PORTE->PCR[14] = 0x00000100;
//	PORTC->PCR[12] = 0x00000110;
//	PORTC->PCR[13] = 0x00000110;
//}
//
//void LPIT0_init (void) {
//	PCC->PCCn[PCC_LPIT_INDEX] = PCC_PCCn_PCS(6); /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
//	PCC->PCCn[PCC_LPIT_INDEX] |= PCC_PCCn_CGC_MASK; /* Enable clk to LPIT0 regs */
//	LPIT0->MCR = 0x00000001; /* DBG_EN-0: Timer chans stop in Debug mode */
//	//LPIT0->MCR = 0x00000100; /* DBG_EN-0: Timer chans stop in Debug mode */
//	/* DOZE_EN=0: Timer chans are stopped in DOZE mode */
//	/* SW_RST=0: SW reset does not reset timer chans, regs */
//	/* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
//	LPIT0->TMR[0].TVAL = 16000000; /* Chan 0 Timeout period: 20M clocks */
//	LPIT0->TMR[1].TVAL = 40000;
//	//LPIT0->TMR[1].TVAL = 40000000;
//	LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
//	LPIT0->TMR[1].TCTRL = 0x00000101;
//	//LPIT0->TMR[1].TCTRL = 0x00000001;
//	/* CHAIN=0: channel chaining is disabled */
//	/* MODE=0: 32 periodic counter mode */
//	/* TSOT=0: Timer decrements immediately based on restart */
//	/* TSOI=0: Timer does not stop after timeout */
//	/* TROT=0 Timer will not reload on trigger */
//	/* TRG_SRC=0: External trigger source */
//	/* TRG_SEL=0: Timer chan 0 trigger source is selected*/
//}
//
//
//
//void WDOG_disable (void) {
//	WDOG->CNT=0xD928C520; /*Unlock watchdog*/
//	WDOG->TOVAL=0x0000FFFF; /*Maximum timeout value*/
//	WDOG->CS = 0x00002100; /*Disable watchdog*/
//}
