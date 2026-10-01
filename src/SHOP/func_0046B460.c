// range: 0x46B460 0x46B490
// auto: m2c draft, verified byte-exact
#include "common.h"

char *func_0046DDD0(M2C_UNK *);                     /* extern */
extern M2C_UNK D_00473B70 __attribute__((section(".data")));

s16 func_0046B460(void) {
    return M2C_FIELD(func_0046DDD0(&D_00473B70), s16 *, 0x10);
}
