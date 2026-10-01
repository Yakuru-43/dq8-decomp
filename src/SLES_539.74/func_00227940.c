// range: 0x227940 0x227980
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00202530();                                /* extern */
M2C_UNK func_00227980(M2C_UNK, M2C_UNK);            /* extern */

void func_00227940(void *arg0) {
    M2C_FIELD(M2C_FIELD(arg0, void **, 0x18), s16 *, 0xA) = (s16) (func_00202530() - 1);
    func_00227980(0, 1);
}
