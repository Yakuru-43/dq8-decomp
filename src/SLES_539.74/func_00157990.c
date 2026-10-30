// range: 0x157990 0x157A40
#include "common.h"

typedef struct {
    /* 00 */ u8 ready : 1;
    /* 01 */ u8 mode : 2;
    /* 03 */ u8 rest : 5;
} Flags22;

typedef struct {
    /* 00 */ u8 pad[0x22];
    /* 22 */ Flags22 flags;
} Obj22;

/* Mark the object ready and latch the requested mode. */
void func_00157990(Obj22 *o, s32 mode) {
    o->flags.ready = 1;
    switch (mode) {
    case 0:
    case 1:
        o->flags.mode = 1;
        break;
    case 2:
        o->flags.mode = 2;
        break;
    case 3:
        o->flags.mode = 3;
        break;
    }
}
