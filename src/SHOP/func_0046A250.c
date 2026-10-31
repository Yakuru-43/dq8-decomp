// range: 0x46A250 0x46A320
#include "common.h"

typedef struct {
    char pad0[4];
    s16 unk4;
} S_351690;

s32 func_0046DDF0();                                      /* extern */
S_351690 *func_351690(s32);                               /* extern */
M2C_UNK func_374700(s32, s32 *, s32 *);                   /* extern */
M2C_UNK func_2D59A0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_2D59C0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);  /* extern */
M2C_UNK func_2D5FF0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_2D70A0(M2C_UNK, M2C_UNK, M2C_UNK);           /* extern */

void func_0046A250(s32 arg0, s32 arg1, s32 arg2) {
    s32 var_5C;
    s32 var_58;
    s32 temp_v0;
    S_351690 *temp_v1;

    temp_v0 = func_0046DDF0();
    temp_v1 = func_351690(arg1);
    if ((temp_v1 != 0) && (0 < arg1)) {
        func_374700(temp_v1->unk4, &var_5C, &var_58);
        func_2D59C0(temp_v0, arg0 + 5, 0, 1);
    } else {
        func_2D59A0(temp_v0, arg0 + 5, 0, 1);
    }
    func_2D5FF0(temp_v0, arg0 + 5, 0, var_5C, var_58);
    func_2D70A0(temp_v0, arg0 + 5, arg2);
}
