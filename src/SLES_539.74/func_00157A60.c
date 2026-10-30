// range: 0x157A60 0x157AF0
#include "common.h"

typedef struct {
    /* 00 */ u8 pad[0x21];
    /* 21 */ u8 rest : 6;
    /* 21 */ u8 bit6 : 1;
    /* 21 */ u8 bit7 : 1;
} Obj21;

/* Latch the flag pair for the requested mode. */
void func_00157A60(Obj21 *o, s32 mode) {
    if (mode == 0) {
        o->bit6 = 0;
        o->bit7 = 0;
    } else if (mode == 1) {
        o->bit7 = 0;
    } else {
        o->bit7 = 1;
    }
}
