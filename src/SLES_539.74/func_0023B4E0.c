// range: 0x23B4E0 0x23B5B0
#include "common.h"

typedef struct Slot23B4E0 {
    /* 0x00 */ s32 type;
    /* 0x04 */ char *ptr;
} Slot23B4E0;

extern char *D_003E0B1C;
char *func_0016D5B0(char *, s32);

s32 func_0023B4E0(char *arg0, s32 arg1) {
    s128 sp20;
    f32 val1;
    f32 val2;
    Slot23B4E0 *sl;
    char *temp_v0;
    s32 a1;

    if (arg1 != 4) {
        return 0;
    }

    if (*(s32 *)arg0 == 1) {
        a1 = (s32)(*(f32 *)(arg0 + 4));
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }

    temp_v0 = func_0016D5B0(D_003E0B1C, a1);
    if (temp_v0 == NULL) {
        return 0;
    }

    sp20 = *(s128 *)(temp_v0 + 0x180);

    sl = (Slot23B4E0 *)(arg0 + 8);
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = *(f32 *)&sp20;
    }

    sl = (Slot23B4E0 *)(arg0 + 0x10);
    val1 = ((f32 *)&sp20)[1];
    if (sl->type == 3) {
        *(f32 *)(sl->ptr + 4) = val1;
    }

    val2 = ((f32 *)&sp20)[2];
    if (((Slot23B4E0 *)(arg0 + 0x18))->type == 3) {
        *(f32 *)(((Slot23B4E0 *)(arg0 + 0x18))->ptr + 4) = val2;
    }

    return 1;
}
