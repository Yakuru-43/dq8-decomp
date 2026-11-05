// range: 0x23D440 0x23D520
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
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ f32 f10;
    /* 0x14 */ f32 f14;
    /* 0x18 */ f32 f18;
    /* 0x1C */ u8 pad1[0xF4];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D440(Arg *args, s32 kind) {
    SlotList *list;
    Slot *slot;
    Arg *p;
    f32 v1;
    f32 v2;
    f32 v3;
    s32 i;

    if (kind != 4) {
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
    v1 = slot->f10;
    p = &args[1];
    if (p->tag == 3) {
        p->value.pf[1] = v1;
    }
    v2 = slot->f14;
    p = &args[2];
    if (p->tag == 3) {
        p->value.pf[1] = v2;
    }
    v3 = slot->f18;
    if (args[3].tag == 3) {
        args[3].value.pf[1] = v3;
    }
    return 1;
}
