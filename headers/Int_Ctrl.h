#ifndef Int_Ctrl_H
#define Int_Ctrl_H

#include "MCU_Regs.h"
#include "Bit_Math.h"
#include "STD.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Lcfg.h"

void IntCtrl_init(void);
void Interrupt_Disable(int Interrupt);
void super_Call(void);

#endif
