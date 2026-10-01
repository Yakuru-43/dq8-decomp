// range: 0x220700 0x220750
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001FFB60();                            /* extern */
M2C_UNK func_00220750();             /* extern */
extern s16 D_003E0A00;

typedef struct {
    char pad0[0x11C4];
    s32 unk11C4;
} S_arg0;

void func_00220700(S_arg0 *arg0, s32 arg1, M2C_UNK arg2) {
    arg0->unk11C4 = -1;
    func_001FFB60();
    func_00220750(arg0, arg2);
    D_003E0A00 = 0;
}
