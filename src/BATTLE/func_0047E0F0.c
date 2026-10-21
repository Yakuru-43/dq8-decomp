// range: 0x47E0F0 0x47E100
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x70];
    s32 unk70;
} S_arg0;

void func_0047E0F0(S_arg0 *arg0, s32 arg1) {
    arg0->unk70 = arg1;
}
