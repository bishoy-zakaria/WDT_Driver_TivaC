#include "WDT.h"

void Wdg_SetTriggerCondition(uint32 timeout_ms)
{
	float32 tick_time=0;
	uint32 tick_num=0;
	uint8 i=0;
	static uint8 counter=0; 
	tick_time = 1/(System_CLK*1000000); //micro second
	tick_num = (timeout_ms *1000)*16;
	if(counter == 0)
	{
	WDTLOAD = tick_num ;
	counter++;
  }
	else
	{
		while ((GET_BIT(WDTCTL,31)) == 0)
	{
		i=i;
	}
	WDTLOAD = tick_num;
	}
}

void Wdg_Init (void)
{
	SET_BIT(RCGCWD,1);
	WDTLOCK |= 0x1ACCE551;
	SET_BIT(WDTCTL,0);
	SET_BIT(WDTCTL,1);
	if(InterruptType == Standard)
		CLR_BIT(WDTCTL,2);
	else
		SET_BIT(WDTCTL,2);
		Wdg_SetTriggerCondition(WdgInitialTimeout);
}

