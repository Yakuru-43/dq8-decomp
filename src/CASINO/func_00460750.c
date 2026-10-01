// range: 0x460750 0x460760
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
} S_arg0;

void func_00460750(S_arg0 *arg0, s32 arg1, s32 arg2) {
    arg0->unk30 = arg1;
    arg0->unk34 = arg2;
}
