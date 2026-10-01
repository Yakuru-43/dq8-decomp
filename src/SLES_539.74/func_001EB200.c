// range: 0x1EB200 0x1EB230
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00166700(s32, s32);                    /* extern */
extern s32 D_003E0748;

s32 func_001EB200(s32 arg0) {
    func_00166700(D_003E0748 + 0x170, arg0);
    return 1;
}
