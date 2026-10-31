// range: 0x1CDEA0 0x1CDEE0
#include "common.h"

M2C_UNK func_001887D0(f32, s32);
extern s32 D_003E0664;

s32 func_001CDEA0(char *arg0) {
    f32 val;

    if (*(s32 *)arg0 == 0) {
        val = (f32)*(s32 *)(arg0 + 4);
    } else {
        val = *(f32 *)(arg0 + 4);
    }
    func_001887D0(val, D_003E0664);
    return 1;
}
