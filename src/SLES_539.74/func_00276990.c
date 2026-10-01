// range: 0x276990 0x276A00
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0021D150(char *, M2C_UNK *);           /* extern */
extern M2C_UNK D_003DD8E0 __attribute__((section(".data")));
extern M2C_UNK D_003DE010 __attribute__((section(".data")));
extern M2C_UNK D_003DE800 __attribute__((section(".data")));
extern M2C_UNK D_003DE840 __attribute__((section(".data")));

char *func_00276990(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE840;
    M2C_FIELD(arg0, s32 *, 8) = 0;
    M2C_FIELD(arg0, s32 *, 4) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE800;
    M2C_FIELD(arg0, M2C_UNK **, 0x60) = &D_003DE010;
    M2C_FIELD(arg0, M2C_UNK **, 0xB0) = &D_003DD8E0;
    func_0021D150(arg0 + 0x10, &D_003DE800);
    return arg0;
}
