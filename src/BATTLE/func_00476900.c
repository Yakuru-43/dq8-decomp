// range: 0x476900 0x476910
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4FC];
    s32 unk4FC;
} S_arg0;

void func_00476900(S_arg0 *arg0, s32 arg1) {
    arg0->unk4FC = arg1;
}
