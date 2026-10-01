// range: 0x47C900 0x47C910
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x24];
    s8 unk24;
} S_arg0;

void func_0047C900(S_arg0 *arg0, s8 arg1) {
    arg0->unk24 = arg1;
}
