// range: 0x1C68F0 0x1C6930
#include "common.h"

M2C_UNK func_001A6660(s32, s32);                    /* extern */
extern s32 D_003E06F4;

s32 func_001C68F0(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_001A6660(D_003E06F4, a1);
    return 1;
}
