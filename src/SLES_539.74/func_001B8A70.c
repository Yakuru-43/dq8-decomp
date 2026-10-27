// range: 0x1B8A70 0x1B8B00
#include "common.h"

M2C_UNK func_0018CBB0(char *, s32);                 /* extern */
M2C_UNK func_002BDBA0(char *, s32, s32, M2C_UNK);   /* extern */
M2C_UNK func_002BEB20(char *, s32, M2C_UNK);        /* extern */
extern char *D_003E0664;

s32 func_001B8A70(char *arg0) {
    char *s0;
    s32 s1;
    s32 a2;

    s0 = D_003E0664;
    if (*(s32 *)arg0 == 1) {
        s1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        s1 = *(s32 *)(arg0 + 4);
    }
    a2 = *(s32 *)(s0 + 0x44B0);
    if (s1 != a2) {
        func_002BDBA0(s0, s1, a2, 0);
    }
    func_0018CBB0(s0, s1);
    func_002BEB20(s0, s1, 1);
    return 1;
}
