// range: 0x2951A0 0x295210
#include "common.h"

s32 func_00297090();                             /* extern */
s32 func_002970A0();                             /* extern */

typedef struct {
    char pad0[0x58C];
    s32 unk58C;
} S_arg0;

s32 func_002951A0(S_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = func_00297090(arg0->unk58C) * 2;
    if (func_002970A0(arg0->unk58C) < temp_s0) {
        return 0;
    }
    func_00297090(arg0->unk58C);
    func_002970A0(arg0->unk58C);
    return 0;
}
