// range: 0x18D680 0x18D720
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001340C0(char *, M2C_UNK *);           /* extern */
u32 func_001341D8(M2C_UNK *);                       /* extern */
M2C_UNK func_0014E750(char *, s32, s32);            /* extern */
M2C_UNK func_0014E860(char *);                      /* extern */
extern M2C_UNK D_003C3108 __attribute__((section(".data")));

void func_0018D680(char *arg0, s32 arg1, s32 arg2) {
    M2C_FIELD(arg0, s32 *, 0x5368) = arg1;
    M2C_FIELD(arg0, s32 *, 0x536C) = arg2;
    func_0014E860(arg0 + 0x5070);
    func_0014E750(arg0 + 0x5070, arg1, arg2);
    if (func_001341D8(&D_003C3108) < 0x10U) {
        func_001340C0(arg0 + 0x5070, &D_003C3108);
    }
    M2C_FIELD(arg0, char **, 0x548) = (char *) (arg0 + 0x5070);
}
