#include "config.h"

#include <stdlib.h>
#include <string.h>
#include <util/delay.h>

#include "game.h"
#include "display.h"
#include "routines.h"

const block pieces[7] = {
	{ "110011000", 3, 0 },
	{ "010111000", 3, 0 },
	{ "100111000", 3, 0 },
	{ "001111000", 3, 0 },
	{ "011110000", 3, 0 },
	{ "1111", 2, 0 },
	{ "0000000100001000010000100", 5, 1 }
};

void eraseFigure(uint8_t figureX, uint8_t figureY) {
    for (uint8_t y = 0; y < figure.size; y++) {
   		for (uint8_t x = 0; x < figure.size; x++) {
   			int8_t offs = (y + figureY) * SCREEN_WIDTH + x + figureX;
    		if (offs >= 0) {
    			screen[offs] &= ((figure.mask[y * figure.size + x] & 1) ^ 1) * 0xff;
    		}
   		}
   	}
}

void placeFigure(block* figure, uint8_t figureX, uint8_t figureY, uint8_t figureColor) {
    for (uint8_t y = 0; y < figure->size; y++) {
   		for (uint8_t x = 0; x < figure->size; x++) {
   			int8_t offs = (y + figureY) * SCREEN_WIDTH + x + figureX;
    		if (offs >= 0) {
    			screen[offs] |= (figure->mask[y * figure->size + x] & 1) * figureColor;
    		}
   		}
   	}
}

uint8_t check(block* figure, int8_t figureX, int8_t figureY) {
    for (int8_t y = 0; y < figure->size; y++) {
   		for (int8_t x = 0; x < figure->size; x++) {
   			int16_t offs = (y + figureY) * SCREEN_WIDTH + x + figureX;
   			// Непустая ячейка в фигуре
   			if (figure->mask[y * figure->size + x] & 1) {
   				// пересечение с заполненной ячейкой стакана
	    		if ((offs >= 0) && (offs < SCREEN_WIDTH * SCREEN_HEIGHT) && (screen[offs] > 0)) {
	    			return 0;
    			}
    			// выходит за границу по горизонтали
    			if ((x + figureX < 0) || (x + figureX >= GLASS_WIDTH)) {
    				return 0;
    			}
    			// выходит за нижнюю границу
    			if (y + figureY >= GLASS_HEIGHT) {
    				return 0;
    			}
    		}
   		}
   	}
	return 1;
}

block next(int8_t* figureX, int8_t* figureY, uint8_t* c) {
	uint8_t i = rand() % 7;
    *figureX = GLASS_WIDTH / 2 - pieces[i].size / 2;
    *figureY = -pieces[i].size;
    *c = (rand() % 2) + 2;
	return pieces[i];
}

void doRotate(block* b) {
	char* tempMask;
	uint8_t tempSize;
	block tempFigure;

	tempSize = b->size;
	tempMask = malloc(tempSize * tempSize);

	for (uint8_t y = 0; y < tempSize; y++) {
		for (uint8_t x = 0; x < tempSize; x++) {
			tempMask[x * tempSize + tempSize - y - 1] = b->mask[y * tempSize + x];
		}
	}

	tempFigure.size = tempSize;
	tempFigure.mask = tempMask;
	tempFigure.upLine = b->upLine;
	eraseFigure(figureX, figureY);
	if (check(&tempFigure, figureX, figureY)) {
		memmove(b->mask, tempMask, tempSize * tempSize);
	}
	free(tempMask);
}

void doLeft() {
	eraseFigure(figureX, figureY);
	if (check(&figure, figureX - 1, figureY)) {
		figureX--;
	}
}

void doRight() {
	eraseFigure(figureX, figureY);
	if (check(&figure, figureX + 1, figureY)) {
		figureX++;
	}
}

uint8_t doDown() {
	eraseFigure(figureX, figureY);
	if (check(&figure, figureX, figureY + 1)) {
		figureY++;
	} else {
		return 0;
	}
	return 1;
}

void doFall() {
	while (doDown());
    placeFigure(&figure, figureX, figureY, figureColor);
	figure = next(&figureX, &figureY, &figureColor);
}

void gameOver(uint8_t* fb) {
	int8_t x, y;
	for (y = SCREEN_HEIGHT - 1; y >= 0; y--) {
		for (x = SCREEN_WIDTH - 1; x >= 0; x--) {
			if (fb[y * SCREEN_WIDTH + x]) {
				fb[y * SCREEN_WIDTH + x] = 1;
			}
			_delay_ms(10);
		}
	}

	while (getButtonStatus() == NONE);
	for (y = 0; y < SCREEN_HEIGHT; y++) {
		for (x = 0; x < SCREEN_WIDTH; x++) {
			fb[y * SCREEN_WIDTH +x] = 0;
		}
	}
	figure = next(&figureX, &figureY, &figureColor);
}

void checkLine(uint8_t* fb) {
	int8_t x, y, i, j;
	for (y = SCREEN_HEIGHT - 1; y >= 0; y--) {
		for (x = 0; x < SCREEN_WIDTH; x++) {
			// поиск пустой ячейки в строке
			if (!fb[y * SCREEN_WIDTH + x]) break;
			// если была найдена пустая ячейка в строке,
			// то в x будет значение меньшее SCREEN_WIDTH-1
			if (SCREEN_WIDTH - 1 == x) {
				// спецэффект очистки строки
				for (i = 0; i < 3; i++) {
					for (x = 0; x < SCREEN_WIDTH; x++) {
						fb[y * SCREEN_WIDTH + x] = 0;
					}
					_delay_ms(25);
					for (x = 0; x < SCREEN_WIDTH; x++) {
						fb[y * SCREEN_WIDTH + x] = 1;
					}
					_delay_ms(25);
				}
				// сдвиг всех строк на одну вниз
				for (j = y - 1; j >= 0; j--) {
					for (i = 0; i < SCREEN_WIDTH; i++) {
						fb[(j + 1) * SCREEN_WIDTH + i] = fb[j * SCREEN_WIDTH + i];
					}
				}
				// стирание самой верхней строки
				for (i = 0; i < SCREEN_WIDTH; i++) fb[i] = 0;
				// проверка всего стакана заново
				y = SCREEN_HEIGHT;
			}
		}
	}
}
