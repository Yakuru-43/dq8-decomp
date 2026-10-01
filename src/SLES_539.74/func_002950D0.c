// range: 0x2950D0 0x295130
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00296BB0();                      /* extern */
s32 func_00297090();                             /* extern */
s32 func_002970A0();                             /* extern */

typedef struct {
    char pad0[0x58C];
    s32 unk58C;
} S_arg0;

s32 func_002950D0(S_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = func_00297090(arg0->unk58C) * 3;
    if (temp_s0 < func_002970A0(arg0->unk58C)) {
        func_00296BB0(arg0);
        return 1;
    }
    return 0;
}
