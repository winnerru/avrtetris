#include <stdint.h>

#define SCREEN_WIDTH                   8
#define SCREEN_HEIGHT                  16

const static uint8_t rowsMap[8] = {3, 2, 5, 4, 1, 0, 6, 7};

uint8_t screen[SCREEN_WIDTH * SCREEN_HEIGHT];

void displayScreen ();
