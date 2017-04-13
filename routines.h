#define _RIGHT 1
#define _UP 2
#define _CENTER 4
#define _DOWN 8
#define _LEFT 16

typedef enum { UP, LEFT, CENTER, RIGHT, DOWN, NONE } buttonStatus;

buttonStatus getButtonStatus();
