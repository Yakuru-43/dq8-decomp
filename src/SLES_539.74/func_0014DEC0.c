// range: 0x14DEC0 0x14DEE0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x24];
    s32 unk24;
} S_arg0;

void func_0014DEC0(S_arg0 *arg0) {
    s32 temp_v1;

    temp_v1 = arg0->unk24;
    if (temp_v1 > 0) {
        arg0->unk24 = (s32) (temp_v1 - 1);
    }
}
