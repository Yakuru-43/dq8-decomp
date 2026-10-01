// range: 0x218410 0x218460
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00168160();                                /* extern */
M2C_UNK func_0020BA80(s32, M2C_UNK *);              /* extern */
M2C_UNK func_0020C3E0(s32);                         /* extern */
extern s8 D_003E0990;
extern s16 D_003E0994;
extern s16 D_003E0998;
extern M2C_UNK D_00415D60 __attribute__((section(".data")));

void func_00218410(void) {
    s32 temp_v0;

    temp_v0 = func_00168160();
    func_0020BA80(temp_v0, &D_00415D60);
    D_003E0998 = 0x19;
    func_0020C3E0(temp_v0);
    D_003E0994 = 0;
    D_003E0990 = 1;
}
