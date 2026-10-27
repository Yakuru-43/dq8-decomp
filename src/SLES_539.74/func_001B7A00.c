// range: 0x1B7A00 0x1B7A40
#include "common.h"

M2C_UNK func_0018CA30(s32, s32);
extern s32 D_003E0664;

s32 func_001B7A00(char *arg0) {
    s32 a1;
    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    func_0018CA30(D_003E0664, a1);
    return 1;
}
