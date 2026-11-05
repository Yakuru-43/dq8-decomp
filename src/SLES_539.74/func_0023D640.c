// range: 0x23D640 0x23D730
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
    /* 0x00 */ u8 pad0[0x48];
    /* 0x48 */ f32 f48;
    /* 0x4C */ f32 f4C;
    /* 0x50 */ u8 pad1[0xC0];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D640(Arg *args, s32 kind) {
    Arg *ap;
    f32 scale;
    f32 offset;
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
        scale = (f32)ap->value.i;
    } else {
        scale = ap->value.f;
    }
    ap = &args[2];
    if (args[2].tag == 0) {
        offset = (f32)ap->value.i;
    } else {
        offset = ap->value.f;
    }
    if (kind >= 4) {
        n = (args[3].tag == 1) ? (s32)args[3].value.f : args[3].value.i;
    }
    end = n + i;
    while (i < end) {
        list = D_003E0B24;
        if (list != 0 && i < list->count) {
            slot = &list->slots[i];
        } else {
            slot = 0;
        }
        if (slot == 0) {
            return 0;
        }
        slot->f48 = scale;
        i = i + 1;
        slot->f4C = offset;
    }
    return 1;
}
