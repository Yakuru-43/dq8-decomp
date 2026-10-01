// range: 0x46BC20 0x46BC30
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x220];
    s32 unk220;
} S_arg0;

void func_0046BC20(S_arg0 *arg0, s32 arg1) {
    arg0->unk220 = arg1;
}
