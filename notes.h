#include <stdint.h>
#include <avr/pgmspace.h>

const uint16_t notes[133] PROGMEM = {
 0,
 16,    17,    18,    19,    21,    22,    23,    25,    26,    28,    29,    31,
 33,    35,    37,    39,    41,    44,    46,    49,    52,    55,    58,    62,
 65,    69,    74,    78,    82,    87,    93,    98,    104,   110,   117,   123,
 131,   139,   148,   156,   165,   175,   185,   196,   207,   220,   233,   247,
 262,   277,   293,   311,   330,   349,   370,   392,   415,   440,   466,   494,
 523,   554,   587,   622,   659,   698,   740,   784,   831,   880,   932,   988,
 1047,  1109,  1175,  1245,  1319,  1397,  1480,  1568,  1661,  1760,  1865,  1976,
 2093,  2217,  2349,  2489,  2637,  2794,  2960,  3136,  3322,  3520,  3729,  3951,
 4186,  4435,  4698,  4978,  5274,  5588,  5920,  6272,  6645,  7040,  7458,  7902,
 8372,  8870,  9397,  9956,  10548, 11175, 11840, 12544, 13290, 14080, 14917, 15804,
 16744, 17739, 18794, 19912, 21096, 22350, 23680, 25088, 26579, 28160, 29834, 31608 };

#define Silence 0

#define C0  1
#define Cd0 2
#define Db0 2
#define D0  3
#define Dd0 4
#define Eb0 4
#define E0  5
#define Fb0 5
#define Ed0 6
#define F0  6
#define Fd0 7
#define Gb0 7
#define G0  8
#define Gd0 9
#define Ab0 9
#define A0  10
#define Ad0 11
#define Hb0 11
#define H0  12
#define Hd0 13


#define Cb1 12
#define C1  13
#define Cd1 14
#define Db1 14
#define D1  15
#define Dd1 16
#define Eb1 16
#define E1  17
#define Fb1 17
#define Ed1 18
#define F1  18
#define Fd1 19
#define Gb1 19
#define G1  20
#define Gd1 21
#define Ab1 21
#define A1  22
#define Ad1 23
#define Hb1 23
#define H1  24
#define Hd1 25


#define Cb2 24
#define C2  25
#define Cd2 26
#define Db2 26
#define D2  27
#define Dd2 28
#define Eb2 28
#define E2  29
#define Fb2 29
#define Ed2 30
#define F2  30
#define Fd2 31
#define Gb2 31
#define G2  32
#define Gd2 33
#define Ab2 33
#define A2  34
#define Ad2 35
#define Hb2 35
#define H2  36
#define Hd2 37


#define Cb3 36
#define C3  37
#define Cd3 38
#define Db3 38
#define D3  39
#define Dd3 40
#define Eb3 40
#define E3  41
#define Fb3 41
#define Ed3 42
#define F3  42
#define Fd3 43
#define Gb3 43
#define G3  44
#define Gd3 45
#define Ab3 45
#define A3  46
#define Ad3 47
#define Hb3 47
#define H3  48
#define Hd3 49


#define Cb4 48
#define C4  49
#define Cd4 50
#define Db4 50
#define D4  51
#define Dd4 52
#define Eb4 52
#define E4  53
#define Fb4 53
#define Ed4 54
#define F4  54
#define Fd4 55
#define Gb4 55
#define G4  56
#define Gd4 57
#define Ab4 57
#define A4  58
#define Ad4 59
#define Hb4 59
#define H4  60
#define Hd4 61


#define Cb5 60
#define C5  61
#define Cd5 62
#define Db5 62
#define D5  63
#define Dd5 64
#define Eb5 64
#define E5  65
#define Fb5 65
#define Ed5 66
#define F5  66
#define Fd5 67
#define Gb5 67
#define G5  68
#define Gd5 69
#define Ab5 69
#define A5  70
#define Ad5 71
#define Hb5 71
#define H5  72
#define Hd5 73


#define Cb6 72
#define C6  73
#define Cd6 74
#define Db6 74
#define D6  75
#define Dd6 76
#define Eb6 76
#define E6  77
#define Fb6 77
#define Ed6 78
#define F6  78
#define Fd6 79
#define Gb6 79
#define G6  80
#define Gd6 81
#define Ab6 81
#define A6  82
#define Ad6 83
#define Hb6 83
#define H6  84
#define Hd6 85


#define Cb7 84
#define C7  85
#define Cd7 86
#define Db7 86
#define D7  87
#define Dd7 88
#define Eb7 88
#define E7  89
#define Fb7 89
#define Ed7 90
#define F7  90
#define Fd7 91
#define Gb7 91
#define G7  92
#define Gd7 93
#define Ab7 93
#define A7  94
#define Ad7 95
#define Hb7 95
#define H7  96
#define Hd7 97


#define Cb8 96
#define C8  97
#define Cd8 98
#define Db8 98
#define D8  99
#define Dd8 100
#define Eb8 100
#define E8  101
#define Fb8 101
#define Ed8 102
#define F8  102
#define Fd8 103
#define Gb8 103
#define G8  104
#define Gd8 105
#define Ab8 105
#define A8  106
#define Ad8 107
#define Hb8 107
#define H8  108
#define Hd8 109


#define Cb9 108
#define C9  109
#define Cd9 110
#define Db9 110
#define D9  111
#define Dd9 112
#define Eb9 112
#define E9  113
#define Fb9 113
#define Ed9 114
#define F9  114
#define Fd9 115
#define Gb9 115
#define G9  116
#define Gd9 117
#define Ab9 117
#define A9  118
#define Ad9 119
#define Hb9 119
#define H9  120
#define Hd9 121


#define Cb10 120
#define C10  121
#define Cd10 122
#define Db10 122
#define D10  123
#define Dd10 124
#define Eb10 124
#define E10  125
#define Fb10 125
#define Ed10 126
#define F10  126
#define Fd10 127
#define Gb10 127
#define G10  128
#define Gd10 129
#define Ab10 129
#define A10  130
#define Ad10 131
#define Hb10 131
#define H10  132
