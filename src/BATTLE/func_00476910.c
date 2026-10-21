// range: 0x476910 0x476930
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1C8];
    s32 unk1C8;
} S_arg0;

void func_00476910(S_arg0 *arg0, M2C_UNK arg1) {
    arg0->unk1C8 = (s32) (arg0->unk1C8 & ~arg1);
}
