// range: 0x4768C0 0x4768D0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4FC];
    s32 unk4FC;
} S_arg0;

void func_004768C0(S_arg0 *arg0, s32 arg1) {
    arg0->unk4FC = arg1;
}
