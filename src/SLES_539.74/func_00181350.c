// range: 0x181350 0x181390
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0014DF80(s32);                         /* extern */
extern s32 D_003E0424;

s32 func_00181350(s32 arg0) {
    if (arg0 == 1) {
        func_0014DF80(D_003E0424 + 0x108);
    }
    return D_003E0424 + 0x108;
}
