// range: 0x4807F0 0x480810
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00474C70(s32);                         /* extern */

typedef struct {
    char pad0[0x4];
    s32 unk4;
} S_arg1;

s32 func_004807F0(s32 arg0, S_arg1 *arg1) {
    func_00474C70(arg1->unk4);
    return 0;
}
