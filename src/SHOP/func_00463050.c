// range: 0x463050 0x4630E0
#include "common.h"

s32 func_00461670();                               /* extern */
s32 func_2205C0(s32, s32, s32);                    /* extern */
s32 func_2D5410(s32, s32);                          /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);       /* extern */
void func_379600(s8);                               /* extern */
extern M2C_UNK D_00473680 __attribute__((section(".data")));
extern M2C_UNK D_44F0F0 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_00463050(S_arg0 *arg0, s32 arg1) {
    if (func_00461670(&D_44F0F0) != 0) {
        return 1;
    }
    if (func_2205C0(func_2D5410(arg1, 0x2746), 0, 0) != 1) {
        return 0;
    }
    func_370C00(arg0->unk20, &D_00473680, 0);
    func_379600(1);
    return 1;
}
