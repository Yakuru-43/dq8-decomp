// best C for func_0023D1E0 (232 vs 240 bytes; see func_0023D1E0.md)
// range: 0x23D1E0 0x23D2D0
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
    /* 0x00 */ u8 pad0[0x40];
    /* 0x40 */ f32 x;
    /* 0x44 */ f32 y;
    /* 0x48 */ u8 pad1[0xC8];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D1E0(Arg *args, s32 kind) {
    Arg *ap;
    f32 y;
    f32 x;
    s32 n = 1;
    s32 i;
    s32 end;
    SlotList *list;
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
        if (args[3].tag == 1) {
            n = (s32)args[3].value.f;
        } else {
            n = args[3].value.i;
        }
    }
    end = n + i;
    for (; i < end; i++) {
        list = D_003E0B24;
        if (list != 0 && i < list->count) {
            slot = &list->slots[i];
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
