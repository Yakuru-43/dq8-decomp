// range: 0x1B8340 0x1B83D0
#include "common.h"

char *func_001B18E0(char *);
s32 func_001B1AA0(char *, s32, s32);
extern s32 D_003E0664;

typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
    char *unk12;
} S_arg0;

s32 func_001B8340(S_arg0 *arg0, s32 arg1) {
    char *temp_v0;
    s32 a2;
    s32 temp_v0_2;

    temp_v0 = func_001B18E0((char *)arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    if (arg1 != 2) {
        return 0;
    }
    if (arg0->unk0 == 1) {
        a2 = (s32)arg0->unk4;
    } else {
        a2 = *(s32 *)&arg0->unk4;
    }
    temp_v0_2 = func_001B1AA0(temp_v0, D_003E0664, a2);
    if (arg0->unk8 == 3) {
        *(s32 *)(arg0->unk12 + 4) = temp_v0_2;
    }
    return 1;
}
