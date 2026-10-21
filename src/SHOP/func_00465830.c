// range: 0x465830 0x465840
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_arg0;

void func_00465830(S_arg0 *arg0, s32 arg1) {
    arg0->unk14 = (s32) (arg0->unk14 | arg1);
}
