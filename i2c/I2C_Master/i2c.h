/*
 * i2c.h
 *
 *  Created on: Nov 1, 2024
 *      Author: Zeina Yehya
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include <stdbool.h>

#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"


#define I2C_PORTB_BASE GPIO_PORTB_BASE
#define slave_address_send 0x3B
#define slave_address_read 0x3B
#define slave_address_init 0x3B

#define Write false
#define Read true


void i2c_master_Init(void);
void i2c_Send(uint8_t data);
uint8_t i2c_master_read(uint8_t data);
void i2c_slave_Init(void);
uint32_t i2c_slave_Read(void);




#endif /* I2C_H_ */
