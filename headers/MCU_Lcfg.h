#ifndef MCU_LCFG_H
#define MCU_LCFG_H
#include"MCU.h"
 
#define XTAL_Frequency          16                 // Frequency speed MHZ
#define MAX_Pripheral_Num        1                 // Maximum number of used pripherals 
#define PLL_Enable               1                 // enable pll 200 MHZ
#define Clock_Source       MainOscillator          // Clock source for the system control      

#endif

/*MCU_Cfg frequency [MAX_Pripheral_Num] = {
		                                         { ADC  , disable  , 20 ,0},
																						 { GPIO , enable   , 20 ,1},
																						 { UART , disable  , 20 ,1}
																					 };
*/