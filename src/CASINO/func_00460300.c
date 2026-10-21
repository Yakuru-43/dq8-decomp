// range: 0x460300 0x460310
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xC];
    s32 unkC;
} S_arg0;

void func_00460300(S_arg0 *arg0, s32 arg1) {
    arg0->unkC = arg1;
}
