#include "gpio.h"

void initGPIO ()
{
        // Enable the GPIOF peripheral for the buttons


    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));

HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;  // Enable changes to PF0
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;

// Configure the button pins as input and output
    GPIOPinTypeGPIOInput(BUTTON_GPIO_BASE, CLOCKWISE_BUTTON_PIN | ANTI_CLOCKWISE_BUTTON_PIN);

    GPIOPinTypeGPIOOutput(BUTTON_GPIO_BASE, RED_BUTTON_PIN | BLUE_BUTTON_PIN | GREEN_BUTTON_PIN);


    GPIOPadConfigSet(BUTTON_GPIO_BASE, CLOCKWISE_BUTTON_PIN | ANTI_CLOCKWISE_BUTTON_PIN, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}
