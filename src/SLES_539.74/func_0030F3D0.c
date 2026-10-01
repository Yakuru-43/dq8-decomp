// range: 0x30F3D0 0x30F450
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0030F450(s32);                         /* extern */
M2C_UNK func_0031D300(s32, s32, s32, s32);          /* extern */
M2C_UNK func_0031E240(s32, s32, M2C_UNK);           /* extern */
M2C_UNK func_0031E250(s32);                         /* extern */
M2C_UNK func_0031E260(s32);                         /* extern */
M2C_UNK func_0031E3B0(s32, M2C_UNK *);              /* extern */
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

void func_0030F3D0(s32 arg0, M2C_UNK arg1) {
    func_0031E250(arg0 + 0x810);
    func_0031E3B0(arg0 + 0x810, &D_0042CDB0);
    func_0031E240(arg0 + 0x810, arg0 + 0xA98, arg1);
    func_0031D300(arg0 + 0x810, arg0 + 0x840, arg0 + 0xA98, arg0 + 0x84C);
    func_0031E260(arg0 + 0x810);
    func_0030F450(arg0 + 0x810);
}
