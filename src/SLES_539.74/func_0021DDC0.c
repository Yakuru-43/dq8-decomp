// range: 0x21DDC0 0x21DE60
#include "common.h"

M2C_UNK func_00133CB8(s32, M2C_UNK *);                 /* extern */
M2C_UNK func_001340C0(s32, M2C_UNK *);                 /* extern */
u32 func_001341D8(M2C_UNK *);                           /* extern */
s32 func_0014E130(M2C_UNK, s32);                       /* extern */
s32 func_00166760(char *);                              /* extern */
extern M2C_UNK D_003C81B0 __attribute__((section(".data")));
extern M2C_UNK D_003E09D8;
extern M2C_UNK *D_003E09E4;

s32 func_0021DDC0(char *arg0) {
    M2C_UNK *obj;
    s32 record;
    u32 len;
    s32 units;

    if (D_003E09E4 == 0) {
        return 0;
    }
    obj = (M2C_UNK *)func_00166760(arg0);
    if (obj == 0) {
        return 0;
    }
    len = func_001341D8(obj);
    units = ((len + 5) % 0x10) != 0 ? (len + 5) / 0x10 + 1 : (len + 5) / 0x10;
    record = func_0014E130(D_003E09D8, units);
    D_003E09E4[1] = record;
    func_001340C0(D_003E09E4[1], obj);
    func_00133CB8(D_003E09E4[1], &D_003C81B0);
    return 1;
}
