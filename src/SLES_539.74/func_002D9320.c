// range: 0x2D9320 0x2D9390
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00190BB0();                    /* extern */
M2C_UNK func_00190BC0();                            /* extern */
M2C_UNK func_002BD8C0();                    /* extern */
f32 func_002D9390();                             /* extern */

void func_002D9320(s32 arg0, char *arg1) {
    if ((arg0 != 0) && (arg1 != NULL)) {
        func_00190BC0();
        func_00190BB0(arg0, arg1 + 0x10);
        func_002BD8C0(arg0, arg1 + 0x20);
        M2C_FIELD(arg1, f32 *, 0x34) = func_002D9390(arg0);
    }
}
