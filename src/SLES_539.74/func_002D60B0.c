// range: 0x2D60B0 0x2D6110
#include "common.h"

void *func_002D7760(void);

void func_002D60B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void *p;

    p = func_002D7760();
    if (p != 0) {
        *(s16 *)((char *)p + 8) = (s16)arg3;
        *(s16 *)((char *)p + 0xA) = (s16)arg4;
        *(s16 *)((char *)p + 0xC) = (s16)arg5;
        *(s16 *)((char *)p + 0xE) = (s16)arg6;
    }
}
