// range: 0x251D60 0x251DA0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK SignalSema(s32);                            /* extern */
M2C_UNK WaitSema(s32);                              /* extern */
s32 func_0011ECC0(s32);                             /* extern */
extern s32 D_003E0BB4;

s32 func_00251D60(s32 arg0) {
    s32 temp_s0;

    WaitSema(D_003E0BB4);
    temp_s0 = func_0011ECC0(arg0);
    SignalSema(D_003E0BB4);
    return temp_s0;
}
