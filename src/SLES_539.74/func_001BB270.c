// range: 0x1BB270 0x1BB2A0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00164060(M2C_UNK *);                   /* extern */
extern M2C_UNK D_003FAFB0 __attribute__((section(".data")));

s32 func_001BB270(void) {
    func_00164060(&D_003FAFB0);
    return 1;
}
