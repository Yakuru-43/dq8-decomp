// range: 0x24B7E0 0x24B840
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00307690(M2C_UNK);                     /* extern */

typedef struct {
    char pad0[0x5C];
    f32 unk5C;
    char pad60[0xC];
    s8 unk6C;
} S_arg0;

s8 func_0024B7E0(S_arg0 *arg0, f32 fparg0) {
    f32 temp_f1;

    if (arg0->unk6C == 1) {
        temp_f1 = arg0->unk5C - fparg0;
        arg0->unk5C = temp_f1;
        if (temp_f1 < 0.0f) {
            func_00307690(0x1E);
            arg0->unk6C = 2;
        }
    }
    return arg0->unk6C;
}
