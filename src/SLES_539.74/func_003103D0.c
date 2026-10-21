// range: 0x3103D0 0x310410
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern void func_00359A90(M2C_UNK *, s32, s32, s32, s32, s32, s32, s32, s32);

void func_003103D0(void) {
    func_00359A90(&D_00421AD0, 0, 0, 0x20, 1, 0, 1, 0, 1);
}
