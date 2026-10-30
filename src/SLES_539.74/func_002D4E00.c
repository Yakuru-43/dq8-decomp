// range: 0x2D4E00 0x2D4E40
#include "common.h"

extern void *func_002D76E0();

void func_002D4E00(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4) {
    void *temp_v0;

    temp_v0 = func_002D76E0();
    if (temp_v0 != NULL) {
        *(u16 *)((char *)temp_v0 + 0) = arg3;
        *(u16 *)((char *)temp_v0 + 2) = arg4;
    }
}
