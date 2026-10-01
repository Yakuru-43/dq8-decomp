// range: 0x3643C0 0x364400
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188(s32, M2C_UNK, M2C_UNK);       /* extern */

typedef struct {
    char pad0[0x1C];
    s32 unk1C;
} S_arg0;

s32 func_003643C0(S_arg0 *arg0) {
    func_00131188(arg0->unk1C, 0, 0x400);
    return arg0->unk1C;
}
