// range: 0x324210 0x3242E8
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *);                       /* extern */
M2C_UNK DebugPrintf2(M2C_UNK *, ...);                 /* extern */
void func_00320EF0(void *, s32, void *, s32);          /* extern */
void func_00320E00(void *, s32);                       /* extern */
extern M2C_UNK D_003D2060 __attribute__((section(".data")));
extern M2C_UNK D_003D2078 __attribute__((section(".data")));
extern s32 D_003E11FC __attribute__((section(".sdata")));
extern s32 D_003E1200 __attribute__((section(".sdata")));
extern M2C_UNK D_00453340 __attribute__((section(".data")));

void func_00324210(s32 arg0, s32 arg1) {
    char buf[0x200];
    s32 n;

    if (arg1 == 0) {
        return;
    }
    n = D_003E11FC + 1;
    if (n >= 4) {
        DebugPrintf(&D_003D2060);
        return;
    }
    D_003E11FC = n;
    DebugPrintf2(&D_003D2078, n);
    func_00320EF0((char *)&D_00453340 + D_003E11FC * 52, arg1, buf, 0x40);
    func_00320E00((char *)&D_00453340 + D_003E11FC * 52, arg0);
    n = D_003E11FC;
    D_003E1200 = n;
    D_003E11FC = n - 1;
}
