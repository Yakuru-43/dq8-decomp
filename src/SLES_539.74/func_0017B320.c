// range: 0x17B320 0x17B370
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001D7AA0();                                /* extern */
M2C_UNK func_001D7AB0(M2C_UNK);                     /* extern */
extern s8 D_003DFC0C;

void func_0017B320(void) {
    D_003DFC0C = -1;
    if (func_001D7AA0() == 1) {
        func_001D7AB0(1);
        D_003DFC0C = 1;
    }
}
