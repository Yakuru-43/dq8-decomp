// range: 0x276F90 0x276FE0
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_0014EA80(s32, M2C_UNK);                    /* extern */

typedef struct {
    s32 unk0;
    s32 unk4;
} S_arg0;

void func_00276F90(S_arg0 *arg0, s32 arg1, M2C_UNK arg2) {
    arg0->unk4 = func_0014EA80(arg1 * 0x10, arg2);
    if (arg0->unk4 != 0) {
        arg0->unk0 = arg1;
    }
}
