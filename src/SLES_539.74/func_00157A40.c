// range: 0x157A40 0x157A60
#include "common.h"

typedef struct {
    /* 00 */ u8 low : 6;
    /* 06 */ u8 shown : 1;
    /* 07 */ u8 high : 1;
} Flags70;

typedef struct {
    /* 00 */ u8 pad[0x21];
    /* 70 */ Flags70 flags;
} Obj70;

/* Show or hide the object. */
void func_00157A40(Obj70 *o, s32 on) {
    o->flags.shown = on;
}
