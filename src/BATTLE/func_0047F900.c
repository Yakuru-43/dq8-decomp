// range: 0x47F900 0x47F910
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x55ED];
    s8 unk55ED;
} S_arg0;

void func_0047F900(S_arg0 *arg0) {
    arg0->unk55ED = 0;
}
