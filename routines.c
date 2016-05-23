#include <avr/io.h>
#include "routines.h"

buttonStatus getButtonStatus () {
		if (!(PINC & _RIGHT)) {
			return RIGHT;
		} else if (!(PINC & _UP)) {
			return UP;
		} else if (!(PINC & _CENTER)) {
			return CENTER;
		} else if (!(PINC & _DOWN)) {
			return DOWN;
		} else if (!(PINC & _LEFT)) {
			return LEFT;
		} else {
			return NONE;
		}
}