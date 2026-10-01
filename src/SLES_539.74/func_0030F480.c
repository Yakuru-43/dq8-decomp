// range: 0x30F480 0x30F510
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00132D38();                                /* extern */
M2C_UNK func_0030F350(char *);                      /* extern */
M2C_UNK func_0030F460();                            /* extern */
M2C_UNK func_0030F510(char *, M2C_UNK *);           /* extern */
M2C_UNK func_0030F520(char *, M2C_UNK *);           /* extern */
M2C_UNK func_0030F530(char *, char *);              /* extern */
M2C_UNK func_0030F540(M2C_UNK *, s32);              /* extern */
extern M2C_UNK D_003E1160;
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_0042CDB0 __attribute__((section(".data")));

void func_0030F480(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0030F460();
    M2C_FIELD(arg0, s32 *, 0xA8C) = arg2;
    M2C_FIELD(arg0, s32 *, 0x1E8) = arg3;
    func_0030F350(arg0 + 0x2C);
    func_0030F540(&D_003E1160, func_00132D38());
    func_0030F530(arg0 + 0x810, arg0 + 0xA84);
    func_0030F520(arg0 + 0x810, &D_00421AD0);
    func_0030F510(arg0 + 0x810, &D_0042CDB0);
}
