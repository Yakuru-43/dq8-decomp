// range: 0x302AC0 0x302B00
#include "common.h"

M2C_UNK func_00302140(M2C_UNK *, s32, u8, M2C_UNK *); /* extern */

void func_00302AC0(M2C_UNK *arg0, s32 arg1, s32 arg2) {
    func_00302140(arg0, arg1, arg2, (M2C_UNK *)((char *)arg0 + 0x1C));
    M2C_FIELD(arg0, u8 *, 0x20) = arg2;
}
