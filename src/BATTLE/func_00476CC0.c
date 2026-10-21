// range: 0x476CC0 0x476CD0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x74];
    s32 unk74;
} S_arg0;

void func_00476CC0(S_arg0 *arg0, s32 arg1) {
    arg0->unk74 = arg1;
}
