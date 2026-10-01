// range: 0x1BFAF0 0x1BFB40
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0017A790();                                /* extern */
s32 func_00182330();                                /* extern */
M2C_UNK func_0022BE70(s32);                         /* extern */
M2C_UNK func_00241740(s32, M2C_UNK);                /* extern */
M2C_UNK func_0025E9D0(M2C_UNK *);                   /* extern */
extern M2C_UNK D_0040F340 __attribute__((section(".data")));

s32 func_001BFAF0(void) {
    func_0022BE70(func_00182330());
    func_0025E9D0(&D_0040F340);
    func_00241740(func_0017A790(), 1);
    return 1;
}
