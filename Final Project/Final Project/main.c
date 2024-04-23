#include <avr/io.h>
#include <util/delay.h>

void init_pwm() {
    // Set PB1 and PB2 as outputs for servo control
    DDRB |= (1 << PB1) | (1 << PB2);
    
    // Configure Timer1 for PWM on PB1 and PB2
    TCCR1A |= (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); // Fast PWM, non-inverting mode for both channels
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Fast PWM, prescaler = 8
    ICR1 = 39999; // 20ms PWM period
}

int main() {
    init_pwm(); // Initialize PWM
    
    while (1) {
        // Set position of first servo (connected to PB1) to 0 degrees
        OCR1A = 1999;
        
        // Set position of second servo (connected to PB2) to 0 degrees
        OCR1B = 1999;
        
        _delay_ms(1000);
        
        // Set position of first servo to 90 degrees
        OCR1A = 3999;
        
        // Set position of second servo to 90 degrees
        OCR1B = 3999;
        
        _delay_ms(1000);
        
        // Set position of first servo to 180 degrees
        OCR1A = 999;
        
        // Set position of second servo to 180 degrees
        OCR1B = 999;
        
        _delay_ms(1000);
    }
    
    return 0;
}



//#include <avr/io.h>
//#include <util/delay.h>
//
//
//void init_pwm() {
//
	//DDRB |= (1<<PB1); // Set PB1 as output
	//
	//DDRB |= (1<<PB0); // Set PB0 as output
//
//
	//TCCR1A |= (1<<COM1A1) | (1<<WGM11); // Fast PWM, non-inverting mode
	//TCCR1B |= (1<<WGM13) | (1<<WGM12) | (1<<CS11); // Fast PWM, prescaler = 8
	//ICR1=39999;   //20ms PWM period
	//
	//TCCR2A |= (1<<COM2A1) | (1<<WGM21); // Fast PWM, non-inverting mode
	//TCCR2B |= (1<<WGM13) | (1<<WGM12) | (1<<CS11); // Fast PWM, prescaler = 8
	//ICR1=39999;   //20ms PWM period
	//
//}
//
//
//int main() {
	//init_pwm(); // Initialize PWM
	//
	//while(1) {
		//
		//OCR1A = 1999; // Set position to 0 degrees
		//_delay_ms(1000);
		//OCR1A = 2999; // Set position to 90 degrees
		//_delay_ms(1000);
		//OCR1A = 3999; // Set position to 180 degrees
		//_delay_ms(1000);
		//
	//}
//
	//return 0;
//}

