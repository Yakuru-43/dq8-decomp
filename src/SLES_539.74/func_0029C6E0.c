// range: 0x29C6E0 0x29C720
#include "common.h"

extern M2C_UNK D_003DEBC0 __attribute__((section(".data")));
extern void func_0029C720(s32, s32);

s32 func_0029C6E0(s32 arg0) {
    func_0029C720(arg0, 0);
    M2C_FIELD(arg0, M2C_UNK **, 4) = &D_003DEBC0;
    return arg0;
}
