// range: 0x329400 0x329430
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} S_arg0;

void func_00329400(S_arg0 *arg0) {
    if (arg0->unk4 == 0) {
        arg0->unk4 = (s32) arg0->unk0;
        arg0->unk8 = 0;
    }
}
