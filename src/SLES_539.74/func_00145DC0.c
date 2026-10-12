// range: 0x145DC0 0x145E00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0015B3F0(s32, s32, s32);               /* extern */

void func_00145DC0(char *arg0) {
    s32 temp_v1;
    char *temp_v0;

    temp_v1 = M2C_FIELD(arg0, s32 *, 0x3B90);

    if (!(temp_v1 != 0)) {
        return;
    }

    temp_v0 = M2C_FIELD(arg0, char **, 0x270);
    func_0015B3F0(temp_v1, M2C_FIELD(temp_v0, s32 *, 0x170), M2C_FIELD(temp_v0, s32 *, 0x174));
}
