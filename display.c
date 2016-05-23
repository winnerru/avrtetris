#include <avr/io.h>
#include "display.h"

/*
PD0 - PD7 - anodes
PC0 - PC4 - buttons
PB0 - latch
PB1 - clk
PB6 - data red
PB7 - data green
*/

inline void sendBitsRG (uint8_t data) {
	PORTB = (data & 3) << 6;
	PORTB |= 2;
	PORTB = 2;
	PORTB = 0;
}

inline void latch () {
	PORTB |= 0b00000001;
	PORTB &= 0b11111110;
}

inline void rowOn (uint8_t row) {
	if (row < 8) {
		PORTD =  0xff ^ (_BV(row));
	}
}

inline void rowOff () {
		PORTD = 0xff;
}

void displayScreen () {
	int8_t x, y;

	for (y = 0; y < 8; y++ ) {
		for (x = 7; x >= 0; x--) {
			sendBitsRG(screen[y << 3 | x | 0x40]);
		}
		for (x = 7; x >= 0; x--) {
			sendBitsRG(screen[y << 3 | x]);
		}
		rowOff();
		latch();
		rowOn(rowsMap[y]);
	}
}
