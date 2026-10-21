// range: 0x46B4A0 0x46B4D0
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0046DDD0(M2C_UNK *);                     /* extern */
extern M2C_UNK D_00473B70 __attribute__((section(".data")));

s16 func_0046B4A0(void) {
    return M2C_FIELD(func_0046DDD0(&D_00473B70), s16 *, 0x10);
}
