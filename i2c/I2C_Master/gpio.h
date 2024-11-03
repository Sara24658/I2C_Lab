#ifndef GPIO_H_
#define GPIO_H_


#include "inc/hw_types.h"
#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/pin_map.h"
#include "driverlib/interrupt.h"

#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"

//#include "tm4c123gh6pm.h"
#include <stdio.h>


#define BUTTON_GPIO_PERIPH                   SYSCTL_PERIPH_GPIOF
#define BUTTON_GPIO_BASE                     GPIO_PORTF_BASE
#define CLOCKWISE_BUTTON_PIN                 GPIO_PIN_0
#define ANTI_CLOCKWISE_BUTTON_PIN            GPIO_PIN_4
#define RED_BUTTON_PIN                       GPIO_PIN_1
#define BLUE_BUTTON_PIN                      GPIO_PIN_2
#define GREEN_BUTTON_PIN                     GPIO_PIN_3

void initGPIO();


#endif /* GPIO_H_ */
