// range: 0x46A0D0 0x46A160
#include "common.h"

M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
s32 func_3715B0(M2C_UNK);                                 /* extern */
M2C_UNK func_37AD80(M2C_UNK);                             /* extern */
M2C_UNK func_37CEA0(M2C_UNK);                             /* extern */
M2C_UNK func_37CEE0(M2C_UNK);                             /* extern */
M2C_UNK func_37D060(M2C_UNK);                             /* extern */
M2C_UNK func_37EA60(M2C_UNK);                             /* extern */
extern s8 D_003E1ACC __attribute__((section(".sdata")));
extern s8 D_003E1AD0 __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_0046A0D0(S_arg0 *arg0, s32 arg1) {
    if (D_003E1ACC != 1) {
        func_37AD80(3);
    } else {
        func_37D060(func_3715B0(arg0->unk18));
        func_37CEE0(1);
        func_37EA60(-1);
        func_2D38E0(arg1, 0x4A6, 0, -1);
        func_37CEA0(0);
        D_003E1ACC = 0;
        D_003E1AD0 = -1;
    }
    return 1;
}
