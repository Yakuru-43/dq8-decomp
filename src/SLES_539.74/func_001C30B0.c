// range: 0x1C30B0 0x1C3160
#include "common.h"

void func_0014E320(char *);
void func_0014E500(s32, char *);
char *func_0014E360(char *, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_0020A110(char *, M2C_UNK32, char *);           /* extern */
s32 func_0020B2A0(char *, M2C_UNK32);                   /* extern */
extern char *D_003E0664;

s32 func_001C30B0(char *arg0) {
    char *temp_s0;
    char *temp_s2;
    s32 temp_s1;

    if (*(s32 *)arg0 == 1) {
        temp_s1 = (s32)*(float *)(arg0 + 4);
    } else {
        temp_s1 = *(s32 *)(arg0 + 4);
    }
    if (func_0020B2A0(D_003E0664, temp_s1) != 0) {
        temp_s0 = *(char **)(D_003E0664 + 0x548);
        temp_s2 = func_0014E360(temp_s0, 2, 0, 0x40);
        func_0014E320(temp_s0);
        func_0014E500((s32)temp_s0, temp_s2);
        func_0020A110(D_003E0664, temp_s1, temp_s2);
        return 1;
    }
    return 0;
}
