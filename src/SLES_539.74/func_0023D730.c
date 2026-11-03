// range: 0x23D730 0x23D870
#include "common.h"

typedef union Vec {
    u128 q;
    struct {
        f32 x, y, z, w;
    } v;
} Vec;

typedef union Value {
    s32 i;
    f32 f;
} Value;

typedef struct {
    s32 tag;
    Value value;
} Arg;

typedef struct {
    /* 0x00 */ u8 pad0[0x20];
    /* 0x20 */ Vec vec;
    /* 0x30 */ u8 pad1[0xE0];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D730(Arg *args, s32 kind) {
    Vec vec;
    Arg *ap;
    f32 val;
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
        val = (f32)ap->value.i;
    } else {
        val = ap->value.f;
    }
    vec.v.x = val;
    ap = &args[2];
    if (args[2].tag == 0) {
        val = (f32)ap->value.i;
    } else {
        val = ap->value.f;
    }
    vec.v.y = val;
    ap = &args[3];
    if (args[3].tag == 0) {
        val = (f32)ap->value.i;
    } else {
        val = ap->value.f;
    }
    vec.v.z = val;
    ap = &args[4];
    if (args[4].tag == 0) {
        val = (f32)ap->value.i;
    } else {
        val = ap->value.f;
    }
    vec.v.w = val;
    if (kind >= 6) {
        n = (args[5].tag == 1) ? (s32)args[5].value.f : args[5].value.i;
    }
    list = D_003E0B24;
    end = n + i;
    for (; i < end; i++) {
        if (list != 0 && i < list->count) {
            slot = &list->slots[i];
        } else {
            slot = 0;
        }
        if (slot == 0) {
            return 0;
        }
        slot->vec = vec;
    }
    return 1;
}
