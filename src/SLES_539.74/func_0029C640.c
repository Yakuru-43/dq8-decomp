// range: 0x29C640 0x29C6A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0029C5D0();                            /* extern */
M2C_UNK func_0029C6A0(s32);                         /* extern */
M2C_UNK func_0029C6E0(s32, M2C_UNK);                /* extern */
M2C_UNK func_0029C740(s32);                         /* extern */
M2C_UNK func_0029C790(s32);                         /* extern */
M2C_UNK func_0031E3C0(s32);                         /* extern */
M2C_UNK func_0031E490(s32);                         /* extern */

s32 func_0029C640(s32 arg0) {
    func_0029C5D0();
    func_0029C790(arg0 + 0x2C);
    func_0031E3C0(arg0 + 0x810);
    func_0029C740(arg0 + 0x840);
    func_0031E490(arg0 + 0x84C);
    func_0029C6E0(arg0 + 0xA84, 0);
    func_0029C6A0(arg0 + 0xA98);
    return arg0;
}
