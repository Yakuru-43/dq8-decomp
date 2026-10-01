// range: 0x468A30 0x468A80
// auto: m2c draft, verified byte-exact
#include "common.h"

s32 func_00467350();                                /* extern */

typedef struct {
    s32 unk0;
} S_arg0;

s32 func_00468A30(S_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = func_00467350();
    if (arg0->unk0 == 3) {
        M2C_FIELD(M2C_FIELD(arg0, char **, 4), s32 *, 4) = temp_v0;
    }
    return 1;
}
