// range: 0x478FF0 0x4790B0
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_00480520 __attribute__((section(".data")));
extern s32 func_130FD0(void *, void *, s32);

s32 func_00478FF0(void *arg0) {
    s32 k;
    s32 i;
    s32 j;

    func_130FD0(&D_00480520, arg0, 0xFC);
    for (i = 0; i < 3; i++) {
        s32 *src = (s32 *)arg0 + 21 * i;
        s32 *dst = (s32 *)&D_00480520 + 21 * i;

        k = 20;
        for (j = 0; j < 21; j++) {
            if (j == 0) {
                dst[j] = src[j];
            } else {
                dst[j] = src[k];
                k--;
            }
        }
    }
    return 1;
}
