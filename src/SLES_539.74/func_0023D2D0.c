// range: 0x23D2D0 0x23D370
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
    f32 *pf;
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

s32 func_0023D2D0(Arg *args, s32 kind) {
    SlotList *list;
    Slot *slot;
    f32 val;
    s32 i;

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
    val = slot->param;
    if (args[1].tag == 3) {
        args[1].value.pf[1] = val;
    }
    return 1;
}
