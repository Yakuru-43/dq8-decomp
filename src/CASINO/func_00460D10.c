// range: 0x460D10 0x460D70
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_2E6740(s32, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_2E72C0(s32, M2C_UNK);                  /* extern */
M2C_UNK func_2FFA80(s32, M2C_UNK, M2C_UNK);         /* extern */

void func_00460D10(s32 arg0, M2C_UNK arg1) {
    func_2FFA80(arg0 + 0xC0, 0, -1);
    func_2E6740(arg0, 0, 0);
    func_2E72C0(arg0, arg1);
}
