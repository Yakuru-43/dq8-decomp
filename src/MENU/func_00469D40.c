// range: 0x469D40 0x469D90
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00469D90(s32, M2C_UNK);                /* extern */
M2C_UNK func_2D38E0(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
s32 func_3715D0(s32);                               /* extern */

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

s32 func_00469D40(S_arg0 *arg0, M2C_UNK arg1) {
    func_2D38E0(arg1, 0x18700, 1, -1);
    func_00469D90(func_3715D0(arg0->unk18), 0);
    return 1;
}
