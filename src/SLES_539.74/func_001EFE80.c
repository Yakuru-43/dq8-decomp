// range: 0x1EFE80 0x1EFEB0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EFEB0();                            /* extern */

typedef struct {
    char pad0[0x8];
    s32 unk8;
} S_arg1;

void func_001EFE80(s32 arg0, S_arg1 *arg1) {
    func_001EFEB0();
    arg1->unk8 = 0;
}
