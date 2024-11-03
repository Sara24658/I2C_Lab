/*
 * i2c.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Zeina Yehya
 */




#include "i2c.h"

void i2c_master_Init(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0))
    {
    }

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB))
    {
    }

    GPIOPinConfigure(GPIO_PB2_I2C0SCL); //PB2  for clock Line
    GPIOPinConfigure(GPIO_PB3_I2C0SDA); //PB3 for Data Line
    GPIOPinTypeI2C(I2C_PORTB_BASE, GPIO_PIN_3);
    GPIOPinTypeI2CSCL(I2C_PORTB_BASE,GPIO_PIN_2);

    I2CMasterEnable(I2C0_BASE);
    I2CMasterInitExpClk(I2C0_BASE, SysCtlClockGet(), false); // false to make the transmission 100kbps

}

void i2c_Send(uint8_t data){
//uint8_t error;
 I2CMasterSlaveAddrSet(I2C0_BASE, slave_address_send, Write);
 I2CMasterDataPut(I2C0_BASE, data);

 I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND); // bnb3t mara wa7da (1 byte)
 while(I2CMasterBusBusy(I2C0_BASE))
 {
 }

 while (I2CMasterErr(I2C0_BASE)!=I2C_MASTER_ERR_NONE){};

}

uint8_t i2c_master_read(uint8_t data)
{
    uint8_t receivedData = 0;
    while (I2CMasterBusBusy(I2C0_BASE)) {
    }
    I2CMasterSlaveAddrSet(I2C0_BASE, slave_address_read, Read);

    I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_RECEIVE);

    while (I2CMasterBusy(I2C0_BASE));

    if (I2CMasterErr(I2C0_BASE) == I2C_MASTER_ERR_NONE) {
        receivedData = I2CMasterDataGet(I2C0_BASE);
    }

    else {

        receivedData = 0xFF;
    }

    return receivedData;

}

void i2c_slave_Init(void)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0))
    {
    }

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB))
    {
    }

    GPIOPinConfigure(GPIO_PB2_I2C0SCL); //PB2  for clock Line
    GPIOPinConfigure(GPIO_PB3_I2C0SDA); //PB3 for Data Line
    GPIOPinTypeI2C(I2C_PORTB_BASE, GPIO_PIN_3);
    GPIOPinTypeI2CSCL(I2C_PORTB_BASE,GPIO_PIN_2);

    I2CSlaveInit(I2C0_BASE, slave_address_init);

}


uint32_t i2c_slave_Read(void)
{
    uint32_t recievedData;
    if (I2CSlaveStatus(I2C0_BASE) == I2C_SLAVE_ACT_RREQ || I2CSlaveStatus(I2C0_BASE) == I2C_SLAVE_ACT_RREQ_FBR)
    {
        recievedData=I2CSlaveDataGet(I2C0_BASE);
    }

    return recievedData;

}

