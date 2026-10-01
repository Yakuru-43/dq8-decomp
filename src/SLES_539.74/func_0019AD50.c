// range: 0x19AD50 0x19AD70
// auto: m2c, verified byte-exact
#include "common.h"

void func_0019AD50(void *arg0, void *arg1, s32 arg2) {
    if (arg1 != NULL) {
        M2C_FIELD(arg0, void **, 0x28) = arg1;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x28), s32 *, 0x50) = arg2;
    }
}
