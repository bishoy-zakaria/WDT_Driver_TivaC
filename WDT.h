#ifndef WDT_H
#define WDT_H
#include "Int_Ctrl.h"
#include "WDT_Cfg.h"
#define Standard       0
#define non maskable   1

void Wdg_Init (void);
void Wdg_SetTriggerCondition ( uint32 timeout );


#endif
