// range: 0x1C2D50 0x1C2E00
#include "common.h"

void func_0014E320(char *);
void func_0014E500(s32, char *);
char *func_0014E360(char *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_00209F30(char *, M2C_UNK32, char *);           /* extern */
s32 func_0020B280(char *, M2C_UNK32);                   /* extern */
extern char *D_003E0664;

s32 func_001C2D50(char *arg0) {
    char *temp_s0;
    char *temp_s2;
    s32 temp_s1;

    if (M2C_FIELD(arg0, s32 *, 0) == 1) {
        temp_s1 = (s32) M2C_FIELD(arg0, f32 *, 4);
    } else {
        temp_s1 = M2C_FIELD(arg0, s32 *, 4);
    }
    if (func_0020B280(D_003E0664, temp_s1) != 0) {
        temp_s0 = M2C_FIELD(D_003E0664, char **, 0x548);
        temp_s2 = func_0014E360(temp_s0, 2, 0, 0x40);
        func_0014E320(temp_s0);
        func_0014E500((s32) temp_s0, temp_s2);
        return func_00209F30(D_003E0664, temp_s1, temp_s2);
    }
    return 0;
}
