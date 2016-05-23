#include "config.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "routines.h"
#include "display.h"

#include "game.h"

void initDevice() {
	DDRB = 0b11000011;
	DDRC = 0b00011111;
	DDRD = 0b11111111;

	PORTB = 0b00000000;
	PORTC = 0b00011111;
	PORTD = 0b11111111;

    // Настройка таймеров
    TCCR0 = (0<<CS02)|(1<<CS01)|(1<<CS00); // Задаём делитель таймера 0

    // настройка обработчиков прерываний
    TIMSK |= (1<<TOIE0);                   // Разрешаем прерывания по переполнению таймера 0

    sei();                                 // Разрешаем прерывания
}

// Обработчик прерывания по переполнению таймера 0
ISR(TIMER0_OVF_vect) {
	displayScreen();
	TCNT0 = 250;
}

int main() {
    uint8_t isButtonReleased = 1;
    uint8_t delayTimer = 0;
    
	initDevice();

    figure = next(&figureX, &figureY, &figureColor);

	for (;;) {
		_delay_ms(1);
		if (++delayTimer > 65) {
			delayTimer = 0;
			if (!doDown()) {
				placeFigure(&figure, figureX, figureY, figureColor);
				checkLine(screen);
				if (figureY < figure.upLine) {
					isButtonReleased = 0;
					gameOver(screen);
				}
				figure = next(&figureX, &figureY, &figureColor);
			} else {
				placeFigure(&figure, figureX, figureY, figureColor);
			}
		}

		switch (getButtonStatus()) {
			case UP:
				if (isButtonReleased) {
		    		gameOver(screen);
				}
				break;
			case LEFT:
				if (isButtonReleased) {
					doLeft();
					placeFigure(&figure, figureX, figureY, figureColor);
				}
				isButtonReleased = 0;
				break;
			case CENTER:
				if (isButtonReleased) {
					doRotate(&figure);
					placeFigure(&figure, figureX, figureY, figureColor);
				}
				isButtonReleased = 0;
				break;
			case RIGHT:
				if (isButtonReleased) {
					doRight();
					placeFigure(&figure, figureX, figureY, figureColor);
				}
				isButtonReleased = 0;
				break;
			case DOWN:
				if (isButtonReleased) {
					doFall();
					placeFigure(&figure, figureX, figureY, figureColor);
					checkLine(screen);
				}
				isButtonReleased = 0;
				break;
			case NONE:
				isButtonReleased = 1;	
				break;
		}
	}
	return 0;
}
