// range: 0x4602C0 0x4602D0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xC];
    s32 unkC;
} S_arg0;

void func_004602C0(S_arg0 *arg0, s32 arg1) {
    arg0->unkC = arg1;
}
