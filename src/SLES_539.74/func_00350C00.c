// range: 0x350C00 0x350CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0016A420(char *);                      /* extern */
s32 func_0018FCE0(char *);                          /* extern */
M2C_UNK func_00190D40(char *);                      /* extern */
s32 func_003135C0(char *, char *, s32);             /* extern */
M2C_UNK func_00313970(char *, M2C_UNK *, M2C_UNK);  /* extern */
s32 func_003515A0();                                /* extern */
extern M2C_UNK D_003D3650 __attribute__((section(".data")));
extern char *D_003E1374;

s32 func_00350C00(s32 arg0, M2C_UNK arg1) {
    if (func_003515A0() != 0) {
        func_0016A420(D_003E1374 + 0x44);
        func_00313970(D_003E1374 + 0x44, &D_003D3650, arg1);
        func_00190D40(D_003E1374 + 0x18F4);
        M2C_FIELD(D_003E1374, s32 *, 0x4C) = func_0018FCE0(D_003E1374 + 0x18F4);
        if (func_003135C0(D_003E1374 + 0x68, D_003E1374 + 0x18F4, M2C_FIELD(D_003E1374, s32 *, 0x3C)) == 0) {
            M2C_FIELD(D_003E1374, s32 *, 0x40) = 1;
            return 0;
        }
        return 1;
    }
    return 1;
}
