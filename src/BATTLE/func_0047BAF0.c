// range: 0x47BAF0 0x47BB60
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_004723B0(M2C_UNK *);                   /* extern */
s32 func_17A620();                                  /* extern */
M2C_UNK func_2A3C90(s32);                           /* extern */
M2C_UNK func_357490(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_4214F8 __attribute__((section(".data")));
extern M2C_UNK D_4218B0 __attribute__((section(".data")));
extern M2C_UNK D_4218F0 __attribute__((section(".data")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));

s32 func_0047BAF0(s32 arg0) {
    if (func_17A620() != 0) {
        return 2;
    }
    func_004723B0(&D_4214F8);
    func_2A3C90(arg0);
    func_357490(&D_421AD0, &D_4218B0, &D_4218F0);
    return 0;
}
