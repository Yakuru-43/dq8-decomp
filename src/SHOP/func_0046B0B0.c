// range: 0x46B0B0 0x46B120
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0046A510();                         /* extern */
s32 func_0046B4A0();                                /* extern */
M2C_UNK func_370E00();             /* extern */
s32 func_3713C0();                   /* extern */

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

s32 func_0046B0B0(S_arg0 *arg0) {
    func_370E00(arg0->unk20, 0, M2C_FIELD(M2C_FIELD(arg0, char **, 0x18), s16 *, 8));
    if (func_3713C0(arg0, 0) != 0) {
        func_0046A510(func_0046B4A0());
    }
    return 1;
}
