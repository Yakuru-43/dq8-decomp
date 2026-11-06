// range: 0x23D910 0x23D9F0
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
    /* 0x00 */ s32 field0;
    /* 0x04 */ u8 pad0[0x10C];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D910(Arg *args, s32 kind) {
    Arg *ap;
    s32 n = 1;
    s32 i;
    s32 val;
    s32 end;
    SlotList *list;
    Slot *slot;

    if (args[0].tag == 1) {
        i = (s32)args[0].value.f;
    } else {
        i = args[0].value.i;
    }
    ap = &args[1];
    if (args[1].tag == 1) {
        val = (s32)ap->value.f;
    } else {
        val = ap->value.i;
    }
    if (kind >= 3) {
        n = (args[2].tag == 1) ? (s32)args[2].value.f : args[2].value.i;
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
        slot->field0 = val;
    }
    return 1;
}
