// range: 0x37B110 0x37B190
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_0018E7C0(s32);                             /* extern */
s32 func_00191EB0(s32);                             /* extern */
s32 func_00192170();                                /* extern */
s32 func_001FF380(M2C_UNK);                         /* extern */
s32 func_002B9FD0();                                /* extern */
s32 func_00308C70(s32);                             /* extern */

s32 func_0037B110(void) {
    if (func_002B9FD0() != 0) {
        goto block_1;
    }
    if ((func_00308C70(func_00191EB0(func_001814D0())) != 0x12) && (func_0018E7C0(func_00192170()) != 0) && (func_001FF380(1) != 1)) {
        return 0;
    }
block_1:
    return 1;
}
