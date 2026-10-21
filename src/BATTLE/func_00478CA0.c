// range: 0x478CA0 0x478CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x690C];
    s32 unk690C;
    s32 unk6910;
    s32 unk6914;
} S_arg0;

void func_00478CA0(S_arg0 *arg0, s32 arg1) {
    arg0->unk690C = arg1;
    arg0->unk6910 = 0;
    arg0->unk6914 = 0;
}
