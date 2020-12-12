#include "Int_Ctrl.h"
extern IntCtrl IntCtrl_Config [Interrupts_Max_Number];


void IntCtrl_init (void)
{
	  int   Loc_InterruptNum = 0;
		int   Loc_GroupPri     = 0;
		int   Loc_SubGroupPri	 =0;
   	int i=0;
	  int Register_offset =0;
	  int Bit_offset=0;
	  int Priority_regs_Offset=0;
	
    asm ("SVC 1");                      
	
    for(i=0; i<Interrupts_Max_Number;i++)
	{
		   Loc_InterruptNum = IntCtrl_Config[i].Interrupt_name;
		   Loc_GroupPri     = IntCtrl_Config[i].Groub_Priority;
		   Loc_SubGroupPri	 = IntCtrl_Config[i].Sub_Groub_Priority;
		
		/*TODO ENABLE\disable configured Interrupts*/
		
		Register_offset = Loc_InterruptNum/32;
		Bit_offset = Loc_InterruptNum%32;
		 NVIC_EN(Register_offset);
		
	  SET_BIT(NVIC_EN(Register_offset),Bit_offset);
		
		/* ******************* priority **************************** */
		
		#if Interrupt_Priority_Levels   ==  0x00
		{
		  uint32 Key = 0x05FA;
		  uint16 Priority_mode=0;
		  uint16 Pri_Offset=0 ;
		  uint32 priority=0;
		  
		  Key << = 16;
		  Intrrupt_Ctrl |= Key; // key
		  
		  Priority_mode = Interrupt_Priority_Levels;
		  Priority_mode << = 8;
		  Intrrupt_Ctrl |= Priority_mode; // xxx
		  
		  Pri_Offset =(Loc_InterruptNum%32)*8 + 5;
		  Priority_regs_Offset = Loc_InterruptNum/4;
		  
		  priority = Loc_GroupPri;
		  priority << = Pri_Offset;
		  
	      NVIC_PRI( Priority_regs_Offset) |= priority ;
			}
		  
		#endif
		
		#if Interrupt_Priority_Levels   ==  0x07
		{
		  uint32 Key = 0x05FA;
		  uint16 Priority_mode=0;
		  uint16 Pri_Offset=0 ;
		  uint32 priority=0;
		  
		  Key  = (Key<<16);
		  Intrrupt_Ctrl |= Key; // key
		  
		  Priority_mode = Interrupt_Priority_Levels;
		  Priority_mode =(Priority_mode<<8);
		  Intrrupt_Ctrl |= Priority_mode; // YYY
			
		  Priority_regs_Offset = Loc_InterruptNum/4;
				
		  Pri_Offset =((Loc_InterruptNum*8)+5) - (32*Priority_regs_Offset) ;
		  
		  priority= Loc_GroupPri;
		  priority = (priority<<Pri_Offset);
		  
	      NVIC_PRI( Priority_regs_Offset) |= priority ;
		  
		  #endif
		}
	}
		
}
