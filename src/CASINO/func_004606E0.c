// range: 0x4606E0 0x460700
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
} S_arg0;

void func_004606E0(S_arg0 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0->unk30;
    *arg2 = arg0->unk34;
}
