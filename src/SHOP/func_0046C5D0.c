// range: 0x46C5D0 0x46C640
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0046B7C0();        /* extern */
s32 func_370E00();                 /* extern */
s32 func_3713C0();                   /* extern */

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046C5D0(S_arg0 *arg0) {
    s32 temp_s0;

    temp_s0 = func_370E00(arg0->unk20, M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 0xE), 0);
    if (func_3713C0(arg0, 1) != 0) {
        func_0046B7C0(arg0, temp_s0, 1);
    }
    return 1;
}
