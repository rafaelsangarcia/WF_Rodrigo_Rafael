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
