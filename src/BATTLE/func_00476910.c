// range: 0x476910 0x476920
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1DC];
    s32 unk1DC;
} S_arg0;

void func_00476910(S_arg0 *arg0, s32 arg1) {
    arg0->unk1DC = arg1;
}
