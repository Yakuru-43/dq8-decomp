// range: 0x47C950 0x47C9C0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_28F730(M2C_UNK *);                     /* extern */
M2C_UNK func_2C7140(s32, s32);                      /* extern */
M2C_UNK func_2C7D80(s32);                           /* extern */
M2C_UNK func_357870(M2C_UNK *, s32);                /* extern */
extern M2C_UNK D_420C30 __attribute__((section(".data")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));

s32 func_0047C950(s32 arg0) {
    s32 var_s0;

    var_s0 = 0;
    do {
        func_2C7140(arg0, var_s0 + 0x80);
        var_s0 += 1;
    } while (var_s0 < 0x10);
    func_28F730(&D_420C30);
    func_357870(&D_421AD0, arg0);
    func_2C7D80(arg0);
    return 0;
}
