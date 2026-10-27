// range: 0x1C7000 0x1C7040
#include "common.h"

M2C_UNK func_001A7480(s32, s32);                    /* extern */
extern s32 D_003E06F4;

s32 func_001C7000(char *arg0) {
    s32 tag;
    s32 a1;

    tag = *(s32 *)arg0;
    if (tag == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_001A7480(D_003E06F4, a1);
    return 1;
}
