// range: 0x47FD80 0x47FE00
#include "common.h"

M2C_UNK func_0046E090(M2C_UNK, s32);            /* extern */
s32 func_1735C0(s32, s32, s32);                 /* extern */
extern s32 D_003E1BD0;

s32 func_0047FD80(s32 arg0, char *arg1, char *arg2) {
    s32 n;
    s32 temp_v0;
    s32 temp_v1;
    char *p;

    temp_v0 = M2C_FIELD(arg1, s32 *, 0xB4);
    if (0 == temp_v0) {
        return 1;
    }
    if (NULL == (char *)(temp_v0 + 8)) {
        return 1;
    }
    p = arg1;
    temp_v1 = M2C_FIELD(arg2, s32 *, 0);
    if (temp_v1 == 1) {
        p = M2C_FIELD(arg2, char **, 0x50);
        n = 0;
    }
    if (temp_v1 == 2) {
        p = M2C_FIELD(arg2, char **, 0x50);
        n = M2C_FIELD(arg2, s32 *, 0x10);
    }
    func_1735C0(func_0046E090(D_003E1BD0, (s32)p), n, 0);
    return 0;
}
