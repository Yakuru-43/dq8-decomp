// range: 0x2E5A60 0x2E5A80
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1624];
    s32 unk1624;
    char pad1628[0x14];
    s32 unk163C;
} S_arg0;

void func_002E5A60(S_arg0 *arg0, s32 arg1) {
    if (arg0->unk1624 < 0) {
        arg0->unk163C = 0;
    }
    arg0->unk1624 = arg1;
}
