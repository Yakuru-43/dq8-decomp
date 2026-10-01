// range: 0x46B910 0x46B920
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x244];
    s16 unk244;
} S_arg0;

void func_0046B910(S_arg0 *arg0) {
    arg0->unk244 = 1;
}
