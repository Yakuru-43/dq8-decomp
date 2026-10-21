// range: 0x472360 0x472370
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x224];
    s32 unk224;
} S_arg0;

void func_00472360(S_arg0 *arg0, s32 arg1) {
    arg0->unk224 = arg1;
}
