#ifndef MCU_H
#define MCU_H

#include "STD.h"
#include "MCU_Regs.h"
#include "Bit_Math.h"
#include "MCU_Lcfg.h"


/* ************************** typedef ************************ */
typedef struct
{
	uint8 pripheral;
	uint8 PLL;
	float32 freq;
	uint8 Pripheral_PORT;
}MCU_Cfg;
typedef uint8 Mcu_PllStatusType ;
typedef uint8 Mcu_ClockType;
typedef uint8 Mcu_RawResetType;
typedef MCU_Cfg Mcu_ConfigType;              //(Clock Source PllUSe Freq)
/* ************************ pripherals ***************************** */

#define	WDT      0
#define	Timer    1
#define	GPIO     2
#define	DMA      3
#define	HIP      4 
#define	UART     5
#define	SSI      6 
#define	I2C      7
#define	USB      8
#define	CAN      9
#define	ADC      10
#define	ACMP     11
#define	PWM      12
#define	QEI      13
#define	EEPROM   14
#define	WTIMER   15

/* ************************ Clock source ***************************** */
#define PrecisionInternalOscillator               0
#define MainOscillator                            1
#define Low_FrequencyInternalOscillator           2
#define HibernationModuleClockSource              3
/* **********************  XTAL definition  ************************* */
#define      XTAL_4_MHz    0x06  
#define      XTAL_5_MHz    0x09  
#define      XTAL_6_MHz    0x0B 
#define      XTAL_8_MHZ    0x0E
#define      XTAL_10_MHz   0x10
#define      XTAL_12_MHz   0x11
#define      XTAL_16_MHz   0x15
#define      XTAL_18_MHz   0x17
#define      XTAL_20_MHz   0x18
#define      XTAL_24_MHz   0x19 
#define      XTAL_25_MHz   0x1A




/* *********************** PLL Configuration *********************** */
#define enable                                    0
#define disable                                   1

/* *********************** API ************************************ */

Mcu_RawResetType Mcu_GetResetRawValue ( void);
void Mcu_PerformReset (void);

void Mcu_Init ( const Mcu_ConfigType * ConfigPtr );
void MCU_Source(void);
void Mcu_InitClock ( void );

void Mcu_DistributePllClock ( void);
Mcu_PllStatusType Mcu_GetPllStatus ( void);

void GPIO_HIGH_Performace(void);

#endif
