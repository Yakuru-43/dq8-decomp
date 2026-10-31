// range: 0x185800 0x185840
#include "common.h"

char * func_0016D5B0(char *, s32);
extern f32 D_003E04C8;

void func_00185800(char *arg0) {
    f32 buf[4];
    char *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = func_0016D5B0(arg0, *(s32 *)(arg0 + 0x44B0));
        if (temp_v0 != NULL) {
            *(s128 *)buf = *(s128 *)(temp_v0 + 0x190);
            D_003E04C8 = buf[1];
        }
    }
}
