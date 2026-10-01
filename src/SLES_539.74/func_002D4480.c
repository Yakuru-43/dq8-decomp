// range: 0x2D4480 0x2D4530
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK DebugPrintf(); /* extern */
char *func_002D4150();                      /* extern */
M2C_UNK func_002D4530();                         /* extern */
extern M2C_UNK D_003CD808 __attribute__((section(".data")));
extern M2C_UNK D_003CD890 __attribute__((section(".data")));

void func_002D4480(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3) {
    char *temp_v0;

    temp_v0 = func_002D4150();
    if (temp_v0 != NULL) {
        if (func_002D4150(arg0, arg2) != NULL) {
            M2C_FIELD(temp_v0, s32 *, 4) = arg2;
        } else {
            DebugPrintf(&D_003CD890, &D_003CD808, arg2, arg1);
        }
    }
    if (arg3 != 0) {
        func_002D4530(arg0);
    }
}
