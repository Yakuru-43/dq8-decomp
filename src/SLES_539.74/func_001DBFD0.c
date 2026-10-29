// range: 0x001DBFD0 0x001DC080
#include "common.h"

typedef struct Slot1DBFD0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot1DBFD0;

s32 func_00210EC0(s32); /* extern */

s32 func_001DBFD0(Slot1DBFD0 *slots) {
    f32 vals[4];
    f32 val1;
    f32 val2;
    s32 result;
    Slot1DBFD0 *sl;

    result = func_00210EC0((s32)vals);
    sl = slots;
    if (sl->type == 3) {
        *(s32 *)(sl->ptr + 4) = result;
    }
    sl = slots + 1;
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = vals[0];
    }
    sl = slots + 2;
    val1 = vals[1];
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = val1;
    }
    val2 = vals[2];
    if (slots[3].type == 3) {
        *(f32 *)(slots[3].ptr + 4) = val2;
    }
    return 1;
}
