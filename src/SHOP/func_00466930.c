// range: 0x466930 0x466980
#include "common.h"

M2C_UNK func_379510(void *, M2C_UNK, M2C_UNK);       /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);        /* extern */
extern M2C_UNK D_00473960 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

void func_00466930(S_arg0 *arg0, M2C_UNK arg1) {
    M2C_UNK result;

    result = func_379510(arg0, arg1, 0);
    if (result == 1000) {
        func_370C00(arg0->unk20, &D_00473960, 0);
    }
}
