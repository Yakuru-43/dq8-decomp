// range: 0x302B90 0x302BC0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00302B00();                            /* extern */
extern s32 D_003E10E4;

s32 func_00302B90(s32 arg0) {
    D_003E10E4 = arg0;
    func_00302B00();
    return arg0;
}
