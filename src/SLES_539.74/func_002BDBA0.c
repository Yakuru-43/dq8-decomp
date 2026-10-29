// range: 0x2BDBA0 0x2BDC80
#include "common.h"

char * func_0016D5B0(char *, s32);
s32 func_001629F0(M2C_UNK *, s32, M2C_UNK);
s32 func_0018D580(char *, M2C_UNK);
M2C_UNK func_002BDB40(char *);
M2C_UNK func_002BDDB0(char *, s32, s32);
M2C_UNK func_002C0740(s32, M2C_UNK *, s32);
extern s32 D_003E0FFC;

void func_002BDBA0(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 sp50[0x80];
    s32 var_s0;

    if (arg1 < 0) {
        return;
    }
    if (arg1 >= 4) {
        return;
    }
    if (D_003E0FFC < 0) {
        return;
    }
    func_002BDB40(func_0016D5B0(arg0, arg2));
    func_002C0740(arg1, (M2C_UNK *)sp50, D_003E0FFC);
    var_s0 = func_0018D580(arg0, 0);
    if (arg3 != 0) {
        var_s0 = arg3;
    }
    if (func_001629F0((M2C_UNK *)sp50, var_s0, 0) != 0) {
        func_002BDDB0(arg0, var_s0, arg1);
    }
}
