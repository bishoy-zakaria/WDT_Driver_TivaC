#ifndef MCU_Regs_H
#define MCU_Regs_H

/************************* NVIC ****************************** */
#define NVIC_EN(x)         (*((volatile uint32*)(0xE000E100+(x*4))))
#define NVIC_DISABLE(x)    (*((volatile uint32*)(0xE000E180+(x*4))))
#define NVIC_PRI(x)        (*((volatile uint32*)(0xE000E400+(x*4))))

/* ************************ SCB ******************************** */
#define Intrrupt_Ctrl      (*((volatile uint32*)(0xE000ED0C )))
	
/* *********************** MCU ******************************* */
#define APINT         (*((volatile uint32*)(0xE000E000+0xD0C)))
#define RESC          (*((volatile uint32*)(0x400FE000+0x05C)))
#define RCC           (*((volatile uint32*)(0x400FE000+0x060)))
#define RCC2          (*((volatile uint32*)(0x400FE000+0x070)))
#define PLLSTAT       (*((volatile uint32*)(0x400FE000+0x168)))
#define GPIOHBCTL     (*((volatile uint32*)(0x400FE000+0x06C)))
/* ******************* Pripherals Gates ************************* */
#define RCGCTIMER     (*((volatile uint32*)(0x400FE000+0x604)))
#define RCGCGPIO      (*((volatile uint32*)(0x400FE000+0x608)))
#define RCGCDMA       (*((volatile uint32*)(0x400FE000+0x60C)))
#define RCGCHIB       (*((volatile uint32*)(0x400FE000+0x614)))
#define RCGCUART      (*((volatile uint32*)(0x400FE000+0x618)))
#define RCGCSSI       (*((volatile uint32*)(0x400FE000+0x61C)))
#define RCGCI2C       (*((volatile uint32*)(0x400FE000+0x620)))
#define RCGCUSB       (*((volatile uint32*)(0x400FE000+0x628)))
#define RCGCCAN       (*((volatile uint32*)(0x400FE000+0x634)))
#define RCGCADC       (*((volatile uint32*)(0x400FE000+0x638)))
#define RCGCACMP      (*((volatile uint32*)(0x400FE000+0x63C)))
#define RCGCPWM       (*((volatile uint32*)(0x400FE000+0x640)))
#define RCGCQEI       (*((volatile uint32*)(0x400FE000+0x644)))
#define RCGCEEPROM    (*((volatile uint32*)(0x400FE000+0x658)))
#define RCGCWTIMER    (*((volatile uint32*)(0x400FE000+0x65C)))

/* **************************** GPIO ****************************** */
#define GPIO_Lock(PORT_Num)                (*((volatile uint32*)(0x40004000+0x520+(1000*PORT_Num))))   
#define GPIO_E_Lock(PORT_Num)              (*((volatile uint32*)(0x40024000+0x520+(1000*PORT_Num))))
#define GPIO_DATA(PORT_Num)                (*((volatile uint32*)(0x400043FC+(1000*PORT_Num)))) 
#define GPIOE_DATA(PORT_Num)               (*((volatile uint32*)(0x400243FC+(1000*PORT_Num)))) 
#define GPIO_DIR(PORT_Num)                 (*((volatile uint32*)(0x40004000+0x400+(1000*PORT_Num))))
#define GPIODR2R(PORT_Num)                 (*((volatile uint32*)(0x40004000+0x500+(1000*PORT_Num))))  //2mA
#define GPIODR4R(PORT_Num)                 (*((volatile uint32*)(0x40004000+0x504+(1000*PORT_Num))))  //4mA
#define GPIODR8R(PORT_Num)                 (*((volatile uint32*)(0x40004000+0x508+(1000*PORT_Num))))  //8mA
#define GPIOODR(PORT_Num)                  (*((volatile uint32*)(0x40004000+0x50C+(1000*PORT_Num))))  //open drain source
#define GPIOPUR(PORT_Num)                  (*((volatile uint32*)(0x40004000+0x510+(1000*PORT_Num))))  //pull up resestor
#define GPIOPDR(PORT_Num)                  (*((volatile uint32*)(0x40004000+0x514+(1000*PORT_Num))))  //pull down resestor
#define GPIODEN(PORT_Num)                  (*((volatile uint32*)(0x40004000+0x51C+(1000*PORT_Num))))  //degital out put
#define GPIOAMSEL(PORT_Num)                (*((volatile uint32*)(0x40004000+0x528+(1000*PORT_Num))))  //analog out put
#define GPIOAFSEL(PORT_Num)                (*((volatile uint32*)(0x40004000+0x420+(1000*PORT_Num))))  //alternative function
#define GPIOPCTL(PORT_Num)                 (*((volatile uint32*)(0x40004000+0x52C+(1000*PORT_Num))))  //control functions of all GPIO pins
	
/* **************************** Watch Dog Timer ************************************* */
#define RCGCWD                             (*((volatile uint32*)(0x400FE000+0x600)))
#define WDTLOAD                            (*((volatile uint32*)(0x40001000)))
#define WDTVALUE                           (*((volatile uint32*)(0x40001000+0x004)))
#define WDTCTL                             (*((volatile uint32*)(0x40001000+0x008)))
#define WDTICR                             (*((volatile uint32*)(0x40001000+0x00C)))
#define WDTRIS                             (*((volatile uint32*)(0x40001000+0x010)))
#define WDTMIS                             (*((volatile uint32*)(0x40001000+0x014)))
#define WDTTEST                            (*((volatile uint32*)(0x40001000+0x418)))
#define WDTLOCK                            (*((volatile uint32*)(0x40001000+0xC00)))

#endif
