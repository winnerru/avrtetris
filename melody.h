#include <stdint.h>
#include <avr/pgmspace.h>

#include "notes.h"

typedef struct {
    uint8_t channel;
    uint8_t note;
    uint8_t delay;
} tMelody;

const tMelody sMelody[247] PROGMEM = {
{ 0, Ad5, 1},
{ 1, Dd6, 1},
{ 2, Dd3, 66},
{ 3, Dd4, 62},
{ 0, G5, 1},
{ 1, Ad5, 1},
{ 2, Dd3, 62},
{ 3, Gd5, 1},
{ 0, H5, 1},
{ 1, Dd4, 63},
{ 2, Ad5, 1},
{ 0, Cd6, 1},
{ 1, Dd3, 63},
{ 3, Dd6, 1},
{ 0, Dd4, 31},
{ 1, Cd6, 32},
{ 2, Gd5, 1},
{ 0, H5, 1},
{ 3, Dd3, 64},
{ 1, G5, 1},
{ 0, Ad5, 1},
{ 2, Dd4, 65},
{ 3, Dd5, 1},
{ 0, Gd5, 1},
{ 1, Gd3, 68},
{ 2, Gd4, 62},
{ 0, Dd5, 1},
{ 1, Gd5, 1},
{ 3, Gd3, 62},
{ 2, Gd5, 1},
{ 0, H5, 1},
{ 1, Gd4, 63},
{ 3, H5, 1},
{ 0, Dd6, 1},
{ 1, Gd3, 63},
{ 2, Gd4, 62},
{ 0, Ad5, 1},
{ 1, Cd6, 1},
{ 3, Gd3, 62},
{ 2, Gd5, 1},
{ 0, H5, 1},
{ 1, Gd4, 63},
{ 3, Ad5, 1},
{ 0, G5, 1},
{ 1, G3, 67},
{ 2, Dd5, 1},
{ 0, G4, 62},
{ 1, G5, 1},
{ 3, G3, 62},
{ 0, H5, 1},
{ 2, Gd5, 1},
{ 1, G4, 63},
{ 3, Ad5, 1},
{ 0, Cd6, 1},
{ 1, Dd3, 63},
{ 2, Dd4, 63},
{ 0, H5, 1},
{ 1, Dd6, 1},
{ 3, Dd3, 64},
{ 2, Dd4, 65},
{ 0, Gd5, 1},
{ 1, H5, 1},
{ 3, Gd3, 68},
{ 2, Gd4, 62},
{ 0, Dd5, 1},
{ 1, Gd5, 1},
{ 3, Gd3, 62},
{ 2, Gd4, 63},
{ 0, Dd5, 1},
{ 1, Gd5, 1},
{ 3, Gd3, 63},
{ 2, Gd4, 62},
{ 0, Ad3, 62},
{ 1, H3, 63},
{ 3, Cd4, 66},
{ 2, Silence, 1},
{ 2, E5, 1},
{ 0, Cd6, 1},
{ 1, Cd3, 125},
{ 3, Gd5, 1},
{ 0, E6, 1},
{ 1, Cd3, 63},
{ 2, Gd6, 1},
{ 0, H5, 63},
{ 1, H5, 1},
{ 3, Cd3, 31},
{ 0, H5, 32},
{ 2, Ad5, 1},
{ 1, Fd6, 1},
{ 3, Gd3, 63},
{ 0, Gd5, 1},
{ 1, E6, 1},
{ 2, E3, 64},
{ 3, Fd5, 1},
{ 0, Dd6, 1},
{ 1, H2, 67},
{ 2, H3, 125},
{ 0, Dd5, 1},
{ 1, H5, 1},
{ 3, H3, 63},
{ 2, Dd6, 1},
{ 0, Fd5, 1},
{ 1, H2, 63},
{ 3, Gd5, 1},
{ 0, Fd3, 30},
{ 1, Fd5, 31},
{ 2, E5, 1},
{ 0, Cd6, 62},
{ 3, Dd5, 1},
{ 1, H5, 1},
{ 0, Fd3, 63},
{ 2, Ad5, 1},
{ 0, G5, 1},
{ 1, Ad3, 67},
{ 3, Dd5, 1},
{ 0, Ad4, 62},
{ 1, G5, 1},
{ 2, Ad5, 62},
{ 0, Gd5, 1},
{ 3, H5, 1},
{ 1, Ad4, 63},
{ 2, Cd6, 1},
{ 0, Ad5, 63},
{ 1, G5, 1},
{ 3, Dd4, 62},
{ 0, Dd6, 1},
{ 2, H5, 62},
{ 1, G5, 1},
{ 3, G4, 63},
{ 0, H5, 1},
{ 2, Gd5, 1},
{ 1, Gd3, 67},
{ 3, Dd5, 1},
{ 0, Dd4, 62},
{ 1, Dd5, 1},
{ 2, Gd5, 1},
{ 0, Gd3, 62},
{ 3, Dd4, 63},
{ 0, Dd5, 1},
{ 1, Gd5, 1},
{ 2, Gd3, 191},
{ 3, Silence, 60},
{ 3, H4, 1},
{ 0, Dd5, 1},
{ 1, Gd3, 67},
{ 2, Dd4, 62},
{ 0, Gd3, 62},
{ 1, Dd4, 61},
{ 3, Silence, 1},
{ 3, Gd4, 1},
{ 2, H4, 1},
{ 0, Gd3, 63},
{ 1, Dd4, 62},
{ 0, Gd3, 62},
{ 2, Dd4, 63},
{ 3, Ad4, 1},
{ 1, Cd5, 1},
{ 0, G3, 67},
{ 2, Dd4, 62},
{ 0, G3, 62},
{ 1, Dd4, 61},
{ 3, Silence, 1},
{ 3, G4, 1},
{ 2, Ad4, 1},
{ 0, G3, 63},
{ 1, Dd4, 63},
{ 0, G3, 64},
{ 2, Dd4, 63},
{ 3, Silence, 2},
{ 3, Gd4, 1},
{ 1, H4, 1},
{ 0, Gd3, 68},
{ 2, Dd4, 62},
{ 0, Gd3, 62},
{ 1, Dd4, 60},
{ 3, Silence, 2},
{ 3, Dd4, 1},
{ 2, Gd4, 1},
{ 0, Gd3, 63},
{ 1, Dd4, 62},
{ 0, Gd3, 62},
{ 2, Dd4, 63},
{ 3, Dd4, 1},
{ 1, G4, 1},
{ 0, G3, 67},
{ 2, Dd4, 62},
{ 0, G3, 62},
{ 1, Dd4, 63},
{ 3, G4, 1},
{ 2, Ad4, 1},
{ 0, G3, 63},
{ 1, Dd4, 63},
{ 0, G3, 64},
{ 2, Dd4, 63},
{ 3, Silence, 2},
{ 3, H4, 1},
{ 1, Dd5, 1},
{ 0, Gd3, 68},
{ 2, Dd4, 62},
{ 0, Gd3, 62},
{ 1, Dd4, 60},
{ 3, Silence, 2},
{ 3, Gd4, 1},
{ 2, H4, 1},
{ 0, Gd3, 63},
{ 1, Dd4, 62},
{ 0, Gd3, 62},
{ 2, Dd4, 63},
{ 3, Ad4, 1},
{ 1, Cd5, 1},
{ 0, G3, 67},
{ 2, Dd4, 62},
{ 0, G3, 62},
{ 1, Dd4, 61},
{ 3, Silence, 1},
{ 3, G4, 1},
{ 2, Ad4, 1},
{ 0, G3, 63},
{ 1, Dd4, 62},
{ 0, G3, 62},
{ 2, Dd4, 63},
{ 3, Gd4, 1},
{ 1, H4, 1},
{ 0, Gd3, 67},
{ 2, Dd4, 62},
{ 0, H4, 1},
{ 1, Dd5, 1},
{ 3, Gd3, 62},
{ 2, Dd4, 63},
{ 0, Dd5, 1},
{ 1, Gd5, 1},
{ 3, Gd3, 63},
{ 2, Dd4, 62},
{ 0, Gd3, 62},
{ 1, Dd4, 63},
{ 3, Dd5, 1},
{ 2, G5, 1},
{ 0, G3, 67},
{ 1, Dd4, 62},
{ 0, G3, 62},
{ 2, Dd4, 61},
{ 3, Silence, 1},
{ 3, G3, 63},
{ 1, Dd4, 62},
{ 0, G3, 62},
{ 2, Dd4, 1},
{ 0, Silence, 0 }
};