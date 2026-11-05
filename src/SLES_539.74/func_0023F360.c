// range: 0x23F360 0x23F410
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

static inline f32 SlotGetFloat(SlotF360 *s) {
    if (s->type == 0) {
        return (f32)s->val;
    }
    return *(f32 *)&s->val;
}

s32 func_0023F360(SlotF360 *slots, s32 arg1) {
    s32 index;

    if (arg1 != 2) {
        return 0;
    }
    index = SlotGetInt(&slots[0]);
    switch (slots[1].type) {
    case 0:
        D_003E0B24->entry[index].i = SlotGetInt(&slots[1]);
        break;
    case 1:
        D_003E0B24->entry[index].f = SlotGetFloat(&slots[1]);
        break;
    case 3:
        return 0;
    default:
        return 0;
    }
    return 1;
}
