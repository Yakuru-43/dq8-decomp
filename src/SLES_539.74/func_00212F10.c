// range: 0x212F10 0x212F90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00133CB8(char *, M2C_UNK *);           /* extern */
M2C_UNK func_001340C0(char *, s32);                 /* extern */
M2C_UNK func_00134750(char *, s32, M2C_UNK);        /* extern */
M2C_UNK func_0018F370(char *, s32);                 /* extern */
extern M2C_UNK D_003C7CD8 __attribute__((section(".data")));
extern char *D_003E0908;
extern s16 D_003E0910;
extern s16 D_003E0914;

s32 func_00212F10(s32 arg0) {
    D_003E0914 = 0;
    D_003E0910 = 0;
    func_001340C0(D_003E0908 + 0x3F4, arg0);
    func_00134750(D_003E0908 + 0x3EC, arg0, 3);
    M2C_FIELD(D_003E0908, s8 *, 0x3EF) = 0;
    func_0018F370(D_003E0908 + 0xEC, arg0);
    func_00133CB8(D_003E0908 + 0xEC, &D_003C7CD8);
    return 0;
}
