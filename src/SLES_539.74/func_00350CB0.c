// range: 0x350CB0 0x350CF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00350200(s32, s32);                    /* extern */
s32 func_003515A0();                                /* extern */
extern s32 D_003E1374;

void func_00350CB0(s32 arg0) {
    if ((func_003515A0() != 0) && (arg0 != 0)) {
        func_00350200(D_003E1374, arg0);
    }
}
