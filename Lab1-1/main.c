#include <stdio.h>
#include "NUC100Series.h"
#include "MCU_init.h"
#include "SYS_init.h"
#include "Scankey.h"

void Init_GPIO(void)
{
      GPIO_SetMode(PC, BIT12, GPIO_MODE_OUTPUT);
      GPIO_SetMode(PC, BIT13, GPIO_MODE_OUTPUT);
      GPIO_SetMode(PC, BIT14, GPIO_MODE_OUTPUT);
      GPIO_SetMode(PC, BIT15, GPIO_MODE_OUTPUT);
      PC12=1; PC13=1; PC14=1; PC15=1;
}

int main(void)
{
    uint32_t i =0;
    SYS_Init();
    OpenKeyPad();
    Init_GPIO();
    
    //Lab1-1
     while(1){
        i=ScanKey();
        switch(i) {
            case 1 : PC12=1; PC13=1; PC14=1; PC15=0; break;
            case 2 : PC12=1; PC13=1; PC14=1; PC15=0; break;
            case 3 : PC12=1; PC13=0; PC14=1; PC15=0; break;
            case 4 : PC12=0; PC13=0; PC14=0; PC15=0; break;
            case 5 : PC12=0; PC13=0; PC14=0; PC15=0; break;
            case 6 : PC12=0; PC13=0; PC14=0; PC15=0; break;
            case 7 : PC12=1; PC13=1; PC14=0; PC15=1; break;
            default: PC12=1; PC13=1; PC14=1; PC15=1; break;
        }
    }
    
    //Lab1-2
    while(1){
        i=ScanKey();
        switch(i) {
            case 1 :
                PC12=0; CLK_SysTickDelay(100000); PC12=1;
                PC13=0; CLK_SysTickDelay(100000); PC13=1;
                PC14=0; CLK_SysTickDelay(100000); PC14=1;
                PC15=0; CLK_SysTickDelay(100000); PC15=1;
                break;
                
            case 2 :
                PC12=0; PC13=0; PC14=0; PC15=0;
                CLK_SysTickDelay(100000);
                PC12=1; PC13=1; PC14=1; PC15=1;
                CLK_SysTickDelay(100000);
                break;
                
            case 3 :
                PC15=0; CLK_SysTickDelay(100000); PC15=1;
                PC14=0; CLK_SysTickDelay(100000); PC14=1;
                PC13=0; CLK_SysTickDelay(100000); PC13=1;
                PC12=0; CLK_SysTickDelay(100000); PC12=1;
                break;
                
            default: PC12=1; PC13=1; PC14=1; PC15=1; break;
        }
    }
}
