// range: 0x476990 0x4769A0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x518];
    s32 unk518;
} S_arg0;

void func_00476990(S_arg0 *arg0, s32 arg1) {
    arg0->unk518 = arg1;
}
