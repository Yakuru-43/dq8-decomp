// range: 0x1B8F70 0x1B8FA0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_001AFA90(M2C_UNK *);                   /* extern */
extern M2C_UNK D_00411D40 __attribute__((section(".data")));

s32 func_001B8F70(void) {
    func_001AFA90(&D_00411D40);
    return 1;
}
