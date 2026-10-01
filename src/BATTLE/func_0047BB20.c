// range: 0x47BB20 0x47BB60
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004723B0(M2C_UNK *);                   /* extern */
M2C_UNK func_1632E0();                              /* extern */
M2C_UNK func_2A3EE0(s32);                           /* extern */
extern M2C_UNK D_4217B8 __attribute__((section(".data")));

s32 func_0047BB20(s32 arg0) {
    func_004723B0(&D_4217B8);
    func_1632E0();
    func_2A3EE0(arg0);
    return 0;
}
