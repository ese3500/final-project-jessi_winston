///*
 //* I2C Driver.c
 //*
 //* Created: 4/23/2024 1:55:02 PM
 //*  Author: jessi
 //*/ 
//
//#include "uart.h"
//
//
//// Start I2C communication
//void I2C_Start() {
	//// Send start condition
	//TWCR0 = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
//}
//
//// Stop I2C communication
//void I2C_Stop() {
	//// Send stop condition
	//TWCR0 = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
//}
//
//// Initialize I2C interface
//void I2C_Init() {
	//// Configure pins for I2C
	//// Set PC4 as input (tri-state)
	//DDRC &= ~(1 << DDC4);
	//// Enable internal pull-up resistor for PC4
	//PORTC |= (1 << DDC4);
	//// Set clock speed
	//TWBR0 = 72; // Formula: TWBR = ((F_CPU / 100) - 16)/2
	//// Initialize I2C peripheral
//}
//
//// Deinitialize I2C interface
//void I2C_Deinit() {
	//// Disable I2C peripheral
	//// Reset pin configurations
//}
//
//// Write data to MPU6050
//void I2C_Write(uint8_t device_address, uint8_t reg_address, uint8_t data) {
	//
	//// Start communication
	//I2C_Start();
	//
	//// Wait for TWINT Flag set. This indicates that the 
	//// START condition has been transmitted.
	 //while (!(TWCR0 & (1<<TWINT)));
	//
	//// Check value of TWI Status Register. Mask
	//// prescaler bits. If status different from
	//// START go to ERROR.
	//if ((TWSR0 & 0xF8) != TWCR0) {
		//ERROR();
	//}
	//
	//// Load SLA_W into TWDR Register. Clear
	//// TWINT bit in TWCR to start transmission of
	//// address.
	//TWDR0 = device_address;
	//TWCR0 = (1<<TWINT) | (1<<TWEN);
	//
	//// Wait for TWINT Flag set. This indicates
	//// that the SLA+W has been transmitted, and
	//// ACK/NACK has been received.
	//while (!(TWCR0 & (1<<TWINT)));
	//
	//
	//// Check value of TWI Status Register. Mask
	//// prescaler bits. If status different from
	//// MT_SLA_ACK go to ERROR.
	//if ((TWSR0 & 0xF8) != MT_SLA_ACK) {
		//ERROR();
	//}
	//
	//// Load DATA into TWDR Register. Clear
	//// TWINT bit in TWCR to start transmission of
	//// data.
	//TWDR0 = data;
	//TWCR0 = (1<<TWINT) | (1<<TWEN);
	//
	//// Wait for TWINT Flag set. This indicates
	//// that the DATA has been transmitted, and
	//// ACK/NACK has been received.
	//while (!(TWCR0 & (1<<TWINT)));
	//
	//// Check value of TWI Status Register. Mask
	//// prescaler bits. If status different from
	//// MT_DATA_ACK go to ERROR.
	//if ((TWSR0 & 0xF8) != MT_DATA_ACK) {
		//ERROR();
	//}
	//
	//// Stop communication
	//I2C_Stop();
//}
//
//// Read data from MPU6050
//uint8_t I2C_Read(uint8_t device_address, uint8_t reg_address) {
	//uint8_t data;
	//
	//// Start communication
	//I2C_Start();
	//
	//// Send device address with write bit
	//// Send register address
	//
	//// Send repeated start condition
	//// Send device address with read bit
	//// Read data
	//
	//// Stop communication
	//I2C_Stop();
	//
	//return data;
//}