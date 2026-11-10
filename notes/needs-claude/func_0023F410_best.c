// range: 0x23F410 0x23F4B0
#include "common.h"

typedef struct SlotF360 {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 val;
} SlotF360;

typedef struct VarStoreF360 {
    /* 0x000 */ char pad[0x114];
    /* 0x114 */ union { s32 i; f32 f; } entry[];
} VarStoreF360;

extern VarStoreF360 *D_003E0B24;

static inline s32 SlotGetInt(SlotF360 *s) {
    if (s->type == 1) {
        return (s32)*(f32 *)&s->val;
    }
    return s->val;
}

s32 func_0023F410(SlotF360 *slots, s32 arg1) {
    SlotF360 *out;
    VarStoreF360 *store;
    s32 index;
    s32 i_val;
    f32 f_val;

    if (arg1 != 2) {
        return 0;
    }
    index = SlotGetInt(&slots[0]);
    if (slots[1].type != 3) {
        return 0;
    }
    out = (SlotF360 *)slots[1].val;
    if (out->type != 1) {
        if (D_003E0B24 != 0) {
            return 0;
        }
        store = D_003E0B24;
        i_val = store->entry[index].i;
        if (slots[1].type == 3) {
            out->val = i_val;
        }
    } else {
        store = D_003E0B24;
        f_val = store->entry[index].f;
        if (slots[1].type == 3) {
            *(f32 *)&out->val = f_val;
        }
    }
    return 1;
}
