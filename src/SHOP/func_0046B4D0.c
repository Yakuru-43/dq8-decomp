// range: 0x46B4D0 0x46B520
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);   /* extern */
M2C_UNK func_370C00(s32, s32, M2C_UNK);                    /* extern */
extern s32 D_003E0168;

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046B4D0(S_arg0 *arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x2733, 0, -1);
    func_370C00(arg0->unk20, D_003E0168, 0);
    return 1;
}
