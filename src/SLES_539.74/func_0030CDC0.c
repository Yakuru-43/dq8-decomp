// range: 0x30CDC0 0x30CE20
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern s32 func_00359A90(M2C_UNK *, s32, void *, s32, s32, s32, s32, s32, s32);
M2C_UNK func_00356910(s32, s32);            /* extern */

void func_0030CDC0(s32 arg0) {
    func_00356910(arg0, func_00359A90(&D_00421AD0, 0, 0, 0x20, 1, 0, 0, -1, 0));
}
