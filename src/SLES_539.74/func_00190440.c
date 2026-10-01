// range: 0x190440 0x190480
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

void func_00190440(S_arg0 *arg0, s32 arg1) {
    arg0->unk20 = (s32) (arg0->unk20 + arg1);
    if (arg0->unk20 < 0) {
        arg0->unk20 = 0;
    }
    if (arg0->unk20 >= 2) {
        arg0->unk20 = 1;
    }
}
