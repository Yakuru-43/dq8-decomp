// range: 0x468550 0x468610
#include "common.h"

char *func_181420(void);
s32 func_203940(char *, s32, s32);

s32 func_00468550(char *self) {
    s32 n;
    s32 ret;
    char *p;

    if (*(s32 *)(self + 0) == 1) {
        n = (s32) *(f32 *)(self + 4);
    } else {
        n = *(s32 *)(self + 4);
    }
    if (-1 < n && n < 4) {
        p = func_181420();
        ret = func_203940(p, n, 0);
        if (*(s32 *)(self + 8) == 3) {
            *(s32 *)(*(s32 *)(self + 0xC) + 4) = ret;
        }
    } else {
        if (*(s32 *)(self + 8) == 3) {
            *(s32 *)(*(s32 *)(self + 0xC) + 4) = -1;
        }
    }
    return 1;
}
