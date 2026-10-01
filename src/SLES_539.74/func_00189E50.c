// range: 0x189E50 0x189E60
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00349650(M2C_UNK *);                   /* extern */
extern M2C_UNK D_0040F2F0 __attribute__((section(".data")));

void func_00189E50(void *arg0, s8 arg1) {
    M2C_FIELD(arg0, s8 *, 0x6A10) = arg1;
    func_00349650(&D_0040F2F0);
}
