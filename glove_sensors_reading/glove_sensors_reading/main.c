/*
 * glove_sensors_reading.c
 *
 * Created: 4/26/2024 12:05:35 AM
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "I2C.h"
#include "MPU6050.h"
#include "uart.h"
#define UART_BAUD_RATE      9600
#define UART_BAUD_PRESCALER (((F_CPU / (UART_BAUD_RATE * 16UL))) - 1)
#define __PRINT_NEW_LINE__  UART_putstring("\r\n");

int flex_sensor_reading;

void ADC_initialize() {
	// Setup for ADC (10bit = 0-1023)
	// Clear power reduction bit for ADC
	PRR0 &= ~(1 << PRADC);
	// Select Vref = AVcc
	ADMUX |= (1 << REFS0);
	ADMUX &= ~(1 << REFS1);
	// Set the ADC clock div by 128
	// 16M/128=125kHz
	ADCSRA |= (1 << ADPS0);
	ADCSRA |= (1 << ADPS1);
	ADCSRA |= (1 << ADPS2);
	// Select Channel ADC0 (pin C0)
	ADMUX &= ~(1 << MUX0);
	ADMUX &= ~(1 << MUX1);
	ADMUX &= ~(1 << MUX2);
	ADMUX &= ~(1 << MUX3);
	ADCSRA |= (1 << ADATE);   // Autotriggering of ADC
	// Free running mode ADTS[2:0] = 000
	ADCSRB &= ~(1 << ADTS0);
	ADCSRB &= ~(1 << ADTS1);
	ADCSRB &= ~(1 << ADTS2);
	// Disable digital input buffer on ADC pin
	DIDR0 |= (1 << ADC0D);
	// Enable ADC
	ADCSRA |= (1 << ADEN);
	// Start conversion
	ADCSRA |= (1 << ADSC);
}
void initialize() {
	ADC_initialize(); // ADC initialization to read flex sensor at pin PC0
	timer2_initialize(); // timer 2 initialization to calculate elapsed time in yaw (z-axis angle)
	UART_init(UART_BAUD_PRESCALER);	
	MPU_init(); // initialize MPU6050
	MPU_write(0x1A, 3); // configure the bandwidth and delay for accelerometer and gyroscope
	MPU_write(0x1B, 0); // configure gyroscope range to default range +- 250 degree/second
	MPU_write(0x1C, 0); // configure accelerometer range to default range +- 2g
}
int main(void)
{
	initialize(); // initialization of Timer2 and MPU
	overflowCount = 0;
	previous_time = 0;
	char bufferAcce[10]; // Buffer to hold the converted number
	char bufferStr2[10]; // Another buffer
    while (1) 
    {
		// Readings from FLEX SENSOR and MPU6050
		get_MPU_readings(); // needed readings sent to the arm: angleX, angleY, GyroZ_converted
		flex_sensor_reading = ADC; // store the reading from ADC to flex_sensor_reading variable
		// Print FLEX SENSOR READING to terminal
		itoa(flex_sensor_reading, bufferStr2, 10);
		UART_putstring("Flex sensor reading: ");
		UART_putstring(bufferStr2);
		__PRINT_NEW_LINE__   // Make space between prints
		// Print ACCELERATION to terminal
		// UART_putstring("Acceleration (m/s^2) in X/Y/Z: ");
		// dtostrf(AcX_converted, 6, 2, bufferAcce);
		// itoa(AcX + 300, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		
		// dtostrf(AcY_converted, 6, 2, bufferAcce);
		// itoa(AcY - 890, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		
		// dtostrf(AcZ_converted, 6, 2, bufferAcce);
		// itoa(AcZ + 484, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		//__PRINT_NEW_LINE__   // Make space between prints

		// Print ANGULAR VELOCITY to terminal
		// UART_putstring("Angular velocity (deg/s) in X/Y/Z: ");
		// dtostrf(GyroX_converted, 6, 2, bufferAcce);
		// itoa(GyroX + 140, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		
		// dtostrf(GyroY_converted, 6, 2, bufferAcce);
		// itoa(GyroY + 75, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		
		// dtostrf(GyroZ_converted, 6, 2, bufferAcce);
		// itoa(GyroZ - 135, bufferStr2, 10);
		// UART_putstring(bufferAcce);
		// UART_putstring(" ~ ");
		// UART_putstring(bufferStr2);
		// UART_putstring(" / ");
		// __PRINT_NEW_LINE__   // Make space between prints

		// UART_putstring("Angle values (X/Y): ");
		// dtostrf(angleX, 6, 2, bufferAcce);
		// UART_putstring(bufferAcce);
		// UART_putstring(" / ");
		// dtostrf(angleY, 6, 2, bufferAcce);
		// UART_putstring(bufferAcce);
		// __PRINT_NEW_LINE__
		// _delay_ms(200);
    }
}

