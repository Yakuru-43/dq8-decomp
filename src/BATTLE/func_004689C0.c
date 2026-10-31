// range: 0x4689C0 0x468A70
#include "common.h"

extern char *D_0042186C __attribute__((section(".data")));
s32 func_181420();
s32 func_205D30(s32, s32);

s32 func_004689C0(char *self) {
    char *p;
    s32 half;

    if (D_0042186C != 0) {
        p = *(char **)(D_0042186C + 0x48);
        half = *(s16 *)(p + 6);
        if (half == func_205D30(func_181420(), 0)) {
            if (*(s32 *)(self + 0) == 3) {
                *(s32 *)(*(s32 *)(self + 4) + 4) = 0;
            }
        } else {
            if (*(s32 *)(self + 0) == 3) {
                *(s32 *)(*(s32 *)(self + 4) + 4) = 1;
            }
        }
    } else {
        if (*(s32 *)(self + 0) == 3) {
            *(s32 *)(*(s32 *)(self + 4) + 4) = 0;
        }
    }
    return 1;
}
