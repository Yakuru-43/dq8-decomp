// range: 0x461640 0x461650
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x15B];
    s8 unk15B;
} S_arg0;

void func_00461640(S_arg0 *arg0) {
    arg0->unk15B = 1;
}
