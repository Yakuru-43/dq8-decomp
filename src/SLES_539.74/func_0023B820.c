// range: 0x23B820 0x23B910
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
} Value;

typedef struct {
    s32 tag;
    Value value;
} Arg;

typedef struct {
    /* 0x00 */ u8 pad0[0xB0];
    /* 0xB0 */ f32 x;
    /* 0xB4 */ f32 y;
    /* 0xB8 */ u8 pad1[0x58];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023B820(Arg *args, s32 kind) {
    Arg *ap;
    f32 y;
    f32 x;
    s32 n = 1;
    s32 i;
    s32 end;
    Slot *slot;

    if (args[0].tag == 1) {
        i = (s32)args[0].value.f;
    } else {
        i = args[0].value.i;
    }
    ap = &args[1];
    if (args[1].tag == 0) {
        x = (f32)ap->value.i;
    } else {
        x = ap->value.f;
    }
    ap = &args[2];
    if (args[2].tag == 0) {
        y = (f32)ap->value.i;
    } else {
        y = ap->value.f;
    }
    if (kind >= 4) {
        n = (args[3].tag == 1) ? (s32)args[3].value.f : args[3].value.i;
    }
    end = i + n;
    for (; i < end; i++) {
        if (D_003E0B24 != 0 && i < D_003E0B24->count) {
            slot = &D_003E0B24->slots[i];
        } else {
            slot = 0;
        }
        if (slot == 0) {
            return 0;
        }
        slot->x = x;
        slot->y = y;
    }
    return 1;
}
