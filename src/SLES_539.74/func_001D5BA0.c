// range: 0x1D5BA0 0x1D5BD0
#include "common.h"

M2C_UNK func_001D2790(char *, s32);                 /* extern */

void func_001D5BA0(char *arg0) {
    s32 temp_a1;

    temp_a1 = M2C_FIELD(arg0, s32 *, 0x38);

    if (!(temp_a1 != 0)) {
        return;
    }

    func_001D2790(arg0, temp_a1);
}
