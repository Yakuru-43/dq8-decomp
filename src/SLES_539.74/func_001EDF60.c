// range: 0x1EDF60 0x1EDFC0
#include "common.h"

void func_00166700(f32 *, s32);
s32 func_001EF2E0(void);
f32 *func_001F77F0(char *, s32);
extern char *D_003E0764;
extern s32 D_003E0784;

s32 func_001EDF60(s32 arg0) {
    f32 *temp_v0;

    if (func_001EF2E0() != 0) {
        return 1;
    }
    temp_v0 = func_001F77F0(D_003E0764, D_003E0784);
    if (temp_v0 == 0) {
        return 0;
    }
    func_00166700(temp_v0 + 4, arg0);
    return 1;
}
