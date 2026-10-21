// range: 0x47ADB0 0x47ADC0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x260];
    s32 unk260;
} S_arg0;

void func_0047ADB0(S_arg0 *arg0, s32 arg1) {
    arg0->unk260 = arg1;
}
