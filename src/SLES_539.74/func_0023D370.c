// range: 0x23D370 0x23D440
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
    /* 0x00 */ u8 pad0[0x50];
    /* 0x50 */ f32 param;
    /* 0x54 */ u8 pad1[0xBC];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D370(Arg *args, s32 kind) {
    Arg *ap;
    f32 val;
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
        val = (f32)ap->value.i;
    } else {
        val = ap->value.f;
    }
    if (kind >= 3) {
        n = (args[2].tag == 1) ? (s32)args[2].value.f : args[2].value.i;
    }
    end = n + i;
    for (; i < end; i++) {
        if (D_003E0B24 != 0 && i < D_003E0B24->count) {
            slot = &D_003E0B24->slots[i];
        } else {
            slot = 0;
        }
        if (slot == 0) {
            return 0;
        }
        slot->param = val;
    }
    return 1;
}
