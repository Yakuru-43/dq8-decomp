// range: 0x26D9E0 0x26DA30
// auto: m2c draft, verified byte-exact
#include "common.h"

extern M2C_UNK D_003DE2C0 __attribute__((section(".data")));
extern M2C_UNK D_003DE3B0 __attribute__((section(".data")));
extern M2C_UNK D_003DE7D0 __attribute__((section(".data")));

char *func_0026D9E0(char *arg0) {
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE7D0;
    M2C_FIELD(arg0, s32 *, 4) = -1;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE3B0;
    M2C_FIELD(arg0, s32 *, 0x14) = 0;
    M2C_FIELD(arg0, s32 *, 0x10) = 0;
    M2C_FIELD(arg0, s128 *, 0x20) = 0;
    M2C_FIELD(arg0, s128 *, 0x30) = 0;
    M2C_FIELD(arg0, M2C_UNK **, 0) = &D_003DE2C0;
    return arg0;
}
