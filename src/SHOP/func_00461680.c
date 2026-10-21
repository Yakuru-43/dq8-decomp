// range: 0x461680 0x461690
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x15B];
    s8 unk15B;
} S_arg0;

void func_00461680(S_arg0 *arg0) {
    arg0->unk15B = 1;
}
