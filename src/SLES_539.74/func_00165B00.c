// range: 0x165B00 0x165B20
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x8];
    s32 unk8;
} S_arg0;

void func_00165B00(S_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk8;
    if (temp_v1 > 0) {
        arg0->unk8 = (s32) (temp_v1 - 1);
    }
}
