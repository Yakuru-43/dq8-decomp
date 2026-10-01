// range: 0x263FB0 0x263FF0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0022A920(M2C_UNK);                     /* extern */
M2C_UNK func_002F7440(s32);                         /* extern */
extern s32 D_003E0CF8;

void func_00263FB0(void) {
    if (D_003E0CF8 != 0) {
        func_002F7440(D_003E0CF8);
    }
    func_0022A920(1);
    D_003E0CF8 = 0;
}
