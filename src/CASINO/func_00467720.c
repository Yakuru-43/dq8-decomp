// range: 0x467720 0x467730
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x24];
    s8 unk24;
} S_arg0;

void func_00467720(S_arg0 *arg0, s8 arg1) {
    arg0->unk24 = arg1;
}
