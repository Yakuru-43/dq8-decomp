// range: 0x46CD80 0x46CE10
// best attempt 2026-11-05 factory-6: CLASS reorder+register score=7
#include "common.h"

s32 func_0046DDF0();                                   /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */

void func_0046CD80(u32 arg0) {
    u32 obj = func_0046DDF0();
    u32 none = (u8)!(0 < arg0);
    u32 some = (u8)!(0 < none);
    func_2D38E0(obj, 0x1F58, some, -1);
    func_2D38E0(obj, 0x1F61, some, -1);
    func_2D38E0(obj, 0x1F4C, none, -1);
}
