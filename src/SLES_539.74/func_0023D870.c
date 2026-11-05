// range: 0x23D870 0x23D910
#include "common.h"

typedef union Value {
    s32 i;
    s32 *p;
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

s32 func_0023D870(Arg *args, s32 kind) {
    SlotList *list;
    Slot *slot;
    s32 i;
    s32 val;

    if (kind != 2) {
        return 0;
    }
    if (args[0].tag == 1) {
        i = (s32)args[0].value.f;
    } else {
        i = args[0].value.i;
    }
    list = D_003E0B24;
    if (list != 0 && i < list->count) {
        slot = &list->slots[i];
    } else {
        slot = 0;
    }
    if (slot == 0) {
        return 0;
    }
    val = slot->field0;
    if (args[1].tag == 3) {
        args[1].value.p[1] = val;
    }
    return 1;
}
