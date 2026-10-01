// range: 0x3086E0 0x308710
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x40];
    s8 unk40;
} S_arg0;

void func_003086E0(S_arg0 *arg0, s32 arg1) {
    arg0->unk40 = (s8) (arg0->unk40 + 1);
    if (arg0->unk40 >= arg1) {
        arg0->unk40 = 0;
    }
}
