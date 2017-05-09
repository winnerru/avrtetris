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

#include "melody.h"

const tMelody* melody;

typedef struct {
    uint16_t fNote;
    uint16_t sPos;
    uint8_t  sWave;
    uint8_t  sVol;
} tPlayerState;

tPlayerState channelState[4];

extern block   figure;
extern uint8_t figureColor;
extern int8_t  figureX, figureY;

uint8_t screen[SCREEN_WIDTH * SCREEN_HEIGHT];

void initDevice() {
    DDRB = 0b11000111;
    DDRC = 0b00000000;
    DDRD = 0b11111111;

    PORTB = 0b00000000;
    PORTC = 0b00011111;
    PORTD = 0b11111111;

    // Настройка таймера 0
    TCCR0 = (0<<CS02)|(1<<CS01)|(1<<CS00);    // Задаём делитель таймера 0

    // Таймер 1 для организации ШИМ звукового генератора на выводе OCR1B
    TCCR1A = 0b00100001;                      // normal PWM mode for ORC1B
    TCCR1B = 0b00001001;                      // FAST 8 bit PWM, no prescaller
    OCR1BL = 0x80;

    // настройка обработчиков прерываний
    TIMSK = (1<<TOIE0)|(1<<TOIE1);            // Разрешаем прерывания по переполнению таймеров 0 и 1

    sei();                                    // Разрешаем прерывания
}

// Обработчик прерывания по переполнению таймера 0
ISR(TIMER0_OVF_vect) {
    static uint8_t y = 0;
    sei();
    displayLine(screen, y);
    if (++y > 7) {
        y = 0;
    }
}

// Обработчик прерывания по переполнению таймера 1
// частота срабатывания - 31,25 КГц
ISR(TIMER1_OVF_vect) {
    static uint16_t _tick = -2;
    static uint16_t _tickMax = 0xffff;
    uint8_t sample = 0;

    if (melody) {

        for (uint8_t i = 0; i < 4; i++) {
            if ((channelState[i].sPos += channelState[i].fNote) >= 15625) {
                channelState[i].sPos -= 15625;
                channelState[i].sWave = (channelState[i].sWave > 0x10) ? ((channelState[i].sWave == 0x10) ? 0x10 : 0) : channelState[i].sVol;
            }
            sample += channelState[i].sWave;
        }

        OCR1BL = sample;

        if (++_tick >= _tickMax) {
            _tick = 0;

            uint8_t channel = pgm_read_byte((uint8_t*)melody);
            uint8_t note = pgm_read_byte((uint8_t*)melody + 1);
            uint8_t delay = pgm_read_word((uint8_t*)melody + 2);

            if ( 0 == delay ) {
                OCR1BL = 0x80;
                _tick = -2;
                melody = NULL;
            } else {
                _tickMax = delay << 7;
                channelState[channel].sPos = 0;
                channelState[channel].fNote = pgm_read_word(&(notes[note]));
                channelState[channel].sVol = (channelState[channel].fNote) ? 0x1f : 0x10;
                melody++;
            }
        }
    }
}

int main() {
    uint8_t isButtonReleased = 1;
    uint8_t delayTimer = 0;

    initDevice();

    melody = sMelody;

    figure = next(&figureX, &figureY, &figureColor);

    for (;;) {
        _delay_us(1350);
        if (++delayTimer > 75) {
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
