// range: 0x46CB60 0x46CC10
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00469C50(s32);                         /* extern */
M2C_UNK func_0046A4C0();                            /* extern */
M2C_UNK func_0046A510(s32);                         /* extern */
M2C_UNK func_0046A6D0(s32);                         /* extern */
M2C_UNK func_0046BA90(M2C_UNK);                     /* extern */
M2C_UNK func_0046CC10(s16, M2C_UNK);                /* extern */
M2C_UNK func_0046CD80(M2C_UNK);                     /* extern */
s32 func_0046D0C0();                                /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_370590(s32, M2C_UNK);                  /* extern */

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

void func_0046CB60(S_arg0 *arg0, M2C_UNK arg1) {
    func_370590(arg0->unk20, 0x28);
    func_0046CD80(0);
    func_0046BA90(0);
    func_0046A6D0(func_0046D0C0());
    func_0046A510(func_0046D0C0());
    func_0046A4C0();
    func_00469C50(func_0046D0C0());
    func_2D38E0(arg1, 0x1F6D, 1, -1);
    func_0046CC10(M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0x12), 1);
}
