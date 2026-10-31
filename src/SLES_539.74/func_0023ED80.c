// range: 0x23ED80 0x23EE10
#include "common.h"

typedef struct Slot23ED80 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot23ED80;

extern char *D_003E0B24;

s32 func_0023ED80(Slot23ED80 *slots, s32 arg1) {
    f32 vals[4];
    f32 val1;
    f32 val2;
    Slot23ED80 *sl;
    char *temp_v0;

    if (arg1 != 3) {
        return 0;
    }
    temp_v0 = *(char **)(D_003E0B24 + 8);
    if (temp_v0 == NULL) {
        return 0;
    }
    *(s128 *)vals = *(s128 *)(temp_v0 + 0x1A0);
    if (slots->type == 3) {
        *(f32 *)(slots->ptr + 4) = vals[0];
    }
    sl = slots + 1;
    val1 = vals[1];
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = val1;
    }
    val2 = vals[2];
    if (slots[2].type == 3) {
        *(f32 *)(slots[2].ptr + 4) = val2;
    }
    return 1;
}
