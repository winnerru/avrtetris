#include <stdint.h>

#define GLASS_WIDTH 8
#define GLASS_HEIGHT 16

typedef struct {
	char* mask;
	uint8_t size;
	uint8_t upLine;
} block;

block   figure;
uint8_t figureColor;
int8_t  figureX, figureY;

uint8_t check(block* figure, int8_t figureX, int8_t figureY);
void placeFigure(block* figure, uint8_t figureX, uint8_t figureY, uint8_t figureColor);
void checkLine(uint8_t* fb);
block next(int8_t* figureX, int8_t* figureY, uint8_t* c);
void doRotate(block* b);
void doLeft();
void doRight();
uint8_t doDown();
void doFall();
void gameOver(uint8_t* fb);