// range: 0x462AA0 0x462AD0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00462B20(s32, M2C_UNK);                /* extern */
s32 func_3715D0(s32);                               /* extern */

typedef struct {
    char pad0[0x18];
    s32 unk18;
} S_arg0;

void func_00462AA0(S_arg0 *arg0) {
    func_00462B20(func_3715D0(arg0->unk18), 1);
}
