

/**
 * main.c
 */
#include "inc/hw_types.h"
#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include <stdio.h>
#include "gpio.h"
#include "i2c.h"

#define LED_ON  0x01
#define LED_OFF 0x00

int main()
{
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);


    i2c_master_Init();

       while(1)
       {

           i2c_Send(LED_ON);
           SysCtlDelay(SysCtlClockGet() / 3);


           i2c_Send(LED_OFF);
           SysCtlDelay(SysCtlClockGet() / 3);
       }
}
