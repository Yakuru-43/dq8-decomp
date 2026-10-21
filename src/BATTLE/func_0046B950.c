// range: 0x46B950 0x46B960
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x244];
    s16 unk244;
} S_arg0;

void func_0046B950(S_arg0 *arg0) {
    arg0->unk244 = 1;
}
