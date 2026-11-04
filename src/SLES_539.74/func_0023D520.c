// range: 0x23D520 0x23D640
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
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ Vec vec;
    /* 0x20 */ u8 pad1[0xF0];
} Slot; /* 0x110 */

typedef struct {
    /* 0x00 */ u8 pad0[0x28];
    /* 0x28 */ Slot *slots;
    /* 0x2C */ s32 count;
} SlotList;

extern SlotList *D_003E0B24;

s32 func_0023D520(Arg *args, s32 kind) {
    Vec vec;
    Arg *ap;
    Arg *bp;
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
    bp = ap + 1;
    if (ap[1].tag == 0) {
        val = (f32)bp->value.i;
    } else {
        val = bp->value.f;
    }
    vec.v.y = val;
    if (ap[2].tag == 0) {
        val = (f32)ap[2].value.i;
    } else {
        val = ap[2].value.f;
    }
    vec.v.z = val;
    vec.v.w = 1.0f;
    if (kind >= 5) {
        n = (args[4].tag == 1) ? (s32)args[4].value.f : args[4].value.i;
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
