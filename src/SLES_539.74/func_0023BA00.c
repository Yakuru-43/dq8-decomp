// range: 0x23BA00 0x23BB60
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
    /* 0x00 */ u8 pad0[0xF0];
    /* 0xF0 */ Vec vec;
    /* 0x100 */ f32 extra;
    /* 0x104 */ s32 flag;
    /* 0x108 */ u8 pad1[8];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023BA00(Arg *args, s32 kind) {
    Vec vec;
    Arg *ap;
    f32 val;
    f32 extra;
    s32 i;
    s32 n = 1;
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
    ap = &args[5];
    if (args[5].tag == 0) {
        extra = (f32)ap->value.i;
    } else {
        extra = ap->value.f;
    }
    if (kind >= 7) {
        n = (args[6].tag == 1) ? (s32)args[6].value.f : args[6].value.i;
    }
    end = i + n;
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
        slot->vec = vec;
        slot->extra = extra;
        slot->flag = 0;
    }
    return 1;
}
