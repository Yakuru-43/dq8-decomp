// range: 0x35C9F0 0x35CA30
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0035CC80();                            /* extern */

typedef struct {
    char pad0[0x98];
    s32 unk98;
    char pad9C[0x8];
    s16 unkA4;
} S_arg0;

s32 func_0035C9F0(S_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = arg0->unk98;
    arg0->unkA4 = 0;
    func_0035CC80();
    return arg0->unk98 - temp_s0;
}
