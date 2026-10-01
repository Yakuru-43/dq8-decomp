// range: 0x220900 0x220990
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00222460(void *);                      /* extern */
M2C_UNK func_002F0B70(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F0B80(void *);                      /* extern */
M2C_UNK func_002F5E90(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F5F70(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F6430();                            /* extern */
s32 func_00370500();                                /* extern */

void func_00220900(void *arg0, s32 arg1) {
    func_002F6430();
    if (arg1 == 0) {
        func_00222460(arg0);
        func_002F5E90(arg0, 1);
        func_002F0B80(arg0);
        func_002F0B70(arg0, 3);
    }
    if (func_00370500() > 0) {
        func_002F5F70(arg0, 0);
        M2C_FIELD(arg0, s8 *, 0x1612) = 1;
    }
}
