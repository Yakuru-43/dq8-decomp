// range: 0x46B6E0 0x46B780
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_22AB50(M2C_UNK);                       /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
extern M2C_UNK D_00479420 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046B6E0(S_arg0 *arg0, M2C_UNK arg1) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x10);
    if ((temp_v1 == 1) || (temp_v1 == 2) || (temp_v1 == 3) || (temp_v1 == 4)) {
        func_22AB50(0);
        func_2D38E0(arg1, 0x4B3, 1, -1);
        func_370C00(arg0->unk20, &D_00479420, 1);
    }
    return 1;
}
