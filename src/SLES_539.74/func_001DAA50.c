// range: 0x1DAA50 0x1DAB00
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_0016B3E0(s32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0016B5F0(s32, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_001DAED0(M2C_UNK);                     /* extern */
M2C_UNK func_00339710(s32);                         /* extern */
void *func_0033A130(s32);                           /* extern */
M2C_UNK func_0033A6F0(void *, M2C_UNK);             /* extern */

void func_001DAA50(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    void *temp_s0;

    temp_s0 = func_0033A130(arg0 + 0x6B34);
    func_001DAED0(arg1);
    if (temp_s0 != NULL) {
        func_0033A6F0(temp_s0, arg2);
        func_00339710(M2C_FIELD(temp_s0, s32 *, 0x184));
    }
    func_0016B5F0(arg0, 1, arg1);
    func_0016B3E0(arg0, 1, arg1, 1);
    func_0016B3E0(arg0, 1, arg1, 4);
}
