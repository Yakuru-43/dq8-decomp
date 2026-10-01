// range: 0x30CCC0 0x30CD00
// auto: m2c draft, verified byte-exact
#include "common.h"

f32 func_00328110(M2C_UNK *);                       /* extern */
M2C_UNK func_003568F0(s32, f32);                    /* extern */
extern M2C_UNK D_003E1160;

void func_0030CCC0(s32 arg0) {
    func_003568F0(arg0, func_00328110(&D_003E1160));
}
