// range: 0x386AF0 0x386B30
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x40];
    s32 unk40;
} S_arg0;

s32 func_00386AF0(S_arg0 *arg0) {
    arg0->unk40 = (s32) (arg0->unk40 + 1);
    if (arg0->unk40 >= 0x2711) {
        arg0->unk40 = 0x2710;
    }
    return arg0->unk40;
}
