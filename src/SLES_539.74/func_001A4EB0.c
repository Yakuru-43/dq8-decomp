// range: 0x1A4EB0 0x1A4EE0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001AC7E0(s32, s32);                    /* extern */

typedef struct {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x24];
    s32 unk68;
} S_arg1;

s32 func_001A4EB0(s32 arg0, S_arg1 *arg1) {
    func_001AC7E0(arg1->unk40, arg1->unk68);
    return 0;
}
