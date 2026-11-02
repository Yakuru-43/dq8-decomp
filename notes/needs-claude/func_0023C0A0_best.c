// range: 0x23C0A0 0x23C1C0
// best attempt (3 of 3; CLASS structural score=60). Attempt 1 (score 45,
// CLASS reorder+register) used if/else for args[0] and `ap = &args[k]` per
// block; the ternary below is what got `i` into $a3.
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
    /* 0x00 */ u8 pad0[0x60];
    /* 0x60 */ Vec vec;
    /* 0x70 */ u8 pad1[0xA0];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023C0A0(Arg *args, s32 kind) {
    Vec vec;
    Arg *ap;
    f32 val;
    s32 n = 1;
    s32 i;
    s32 end;
    SlotList *list;
    Slot *slot;

    i = (args[0].tag == 1) ? (s32)args[0].value.f : args[0].value.i;
    ap = &args[1];
    if (ap[0].tag == 0) {
        val = (f32)ap[0].value.i;
    } else {
        val = ap[0].value.f;
    }
    vec.v.x = val;
    if (ap[1].tag == 0) {
        val = (f32)ap[1].value.i;
    } else {
        val = ap[1].value.f;
    }
    vec.v.y = val;
    if (ap[2].tag == 0) {
        val = (f32)ap[2].value.i;
    } else {
        val = ap[2].value.f;
    }
    vec.v.z = val;
    vec.v.w = 0;
    if (kind >= 5) {
        n = (args[4].tag == 1) ? (s32)args[4].value.f : args[4].value.i;
    }
    list = D_003E0B24;
    end = i + n;
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
