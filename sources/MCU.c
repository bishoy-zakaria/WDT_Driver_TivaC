#include"MCU_Lcfg.h"

const Mcu_ConfigType * MCU_PTR ;               // Global variable for the cofiguration

Mcu_RawResetType Mcu_GetResetRawValue ( void)
{
	uint8 regs_val=0;
	regs_val = (RESC & (0x0001003F)) ;
	return regs_val;
}

void Mcu_PerformReset(void)
{
	SET_BIT(APINT , 2);
}

/* *********************** CLOCK_CFG ***************************

MCU_arr = { { Pripheral , PLL , Frequency , PORT } };*/

void Mcu_Init ( const Mcu_ConfigType * ConfigPtr )
{
	MCU_PTR = ConfigPtr ;
}

Mcu_PllStatusType Mcu_GetPllStatus ( void)
{
	uint8 status =0;
	CLR_BIT(RCC,0);
	CLR_BIT(RCC,13);
	status=GET_BIT(PLLSTAT,0);
	return status;
}

void Mcu_DistributePllClock ( void)
{
	uint8 n=0;
	n = Mcu_GetPllStatus();
	while(n != 1)
	{
		n=n;
	}
	CLR_BIT(RCC,11);
}

void MCU_Source(void)
{
	uint8 i=0;
	RCC |= (XTAL_16_MHz << 6);                     // initialization for the crystal
  	for (i=0 ; i< MAX_Pripheral_Num ;i++)
	{
		if (((MCU_PTR[i].freq)/ XTAL_Frequency) <= 16) // use RCC register
		{
			if      (Clock_Source   ==    MainOscillator )
				RCC = RCC | (0x00000000);
			else if (Clock_Source   ==    PrecisionInternalOscillator)
		    RCC = RCC | (0x00000010);
			else if (Clock_Source   ==    HibernationModuleClockSource  )
				RCC = RCC | (0x00000020);
			else if (Clock_Source   ==    Low_FrequencyInternalOscillator)
				RCC = RCC | (0x00000030);
		}
		else
		{
			SET_BIT(RCC2,31);           // use RCC2 to earn more dirivates
      
      if      (Clock_Source   ==    MainOscillator )
				RCC2 = RCC2 | (0x00000000);
			else if (Clock_Source   ==    PrecisionInternalOscillator)
		    RCC2 = RCC2 | (0x00000010);
			else if (Clock_Source   ==    HibernationModuleClockSource  )
				RCC2 = RCC2 | (0x00000020);
			else if (Clock_Source   ==    Low_FrequencyInternalOscillator)
				RCC2 = RCC2 | (0x00000030);
		}
	}
	
}

void Mcu_InitClock ( void )
{
	uint8 i=0;
	uint8 Div = 0;
	uint8 Div_PLL = 0;
	
	MCU_Source(); // initialization for the clock source
	
	for(i =0; i< MAX_Pripheral_Num ;i++)
	{
		/* ***************** Gating ************************* */
		if ( MCU_PTR[i].pripheral == WDT )
		SET_BIT(RCGCWD,MCU_PTR[i].Pripheral_PORT);	
		else if (MCU_PTR[i].pripheral == Timer)
		SET_BIT(RCGCTIMER,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == GPIO)
		SET_BIT(RCGCGPIO,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == DMA)
		SET_BIT(RCGCDMA,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == HIP)
		SET_BIT(RCGCHIB,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == UART)
		SET_BIT(RCGCUART,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == SSI)
		SET_BIT(RCGCSSI,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == I2C)
		SET_BIT(RCGCI2C,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == USB)
		SET_BIT(RCGCUSB,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == CAN)
		SET_BIT(RCGCCAN,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == ADC)
		SET_BIT(RCGCADC,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == ACMP)
		SET_BIT(RCGCACMP,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == PWM)
		SET_BIT(RCGCPWM,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == QEI)
		SET_BIT(RCGCQEI,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == EEPROM)
		SET_BIT(RCGCEEPROM,MCU_PTR[i].Pripheral_PORT);
		else if (MCU_PTR[i].pripheral == WTIMER)
		SET_BIT(RCGCWTIMER,MCU_PTR[i].Pripheral_PORT);
		
		/* **************** SET Frequency ******************* */
		
		Div = XTAL_Frequency / MCU_PTR[i].freq;
		Div_PLL = 200 / MCU_PTR[i].freq;
		
		if ( MCU_PTR[i].freq < XTAL_Frequency )
		{
			if (Div < 16)             // Using RCC 
			{
				SET_BIT(RCC,22);       // using division bit
				SET_BIT(RCC,11);       // Disable PLL
				RCC |= ((Div-1) << 23);
			}
			else                     
			{
				SET_BIT(RCC2,31);        // using RCC2
				SET_BIT(RCC2,11);       // Disable PLL
				RCC2 |= ((Div-1) << 23);
			}
		}
		
		else                       // will use PLL to multiplicate the frequency
		{
			if(MCU_PTR[i].PLL == enable)
			{
			 SET_BIT(RCC,22);	
			 RCC |= ((Div_PLL-1) << 23);
			 Mcu_DistributePllClock();
			}
		}
		
	}
}
void GPIO_HIGH_Performace(void)
{
	GPIOHBCTL |= 0xFF;
}


