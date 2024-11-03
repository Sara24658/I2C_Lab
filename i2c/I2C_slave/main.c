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


int main()
{
    uint32_t receivedCommand;
    SysCtlClockSet(SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);


    i2c_slave_Init();
    initGPIO();

    while(1)
    {
        receivedCommand = i2c_slave_Read();

               if(receivedCommand == 0x01)
               {
                   GPIOPinWrite(GPIO_PORTF_BASE, RED_BUTTON_PIN, 0x02);
               }
               else if(receivedCommand == 0x00)
               {
                   GPIOPinWrite(GPIO_PORTF_BASE, RED_BUTTON_PIN, 0);
               }
    }


return 0;
}
