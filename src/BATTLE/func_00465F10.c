// range: 0x465F10 0x465F20
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1];
    s8 unk1;
} S_arg0;

void func_00465F10(S_arg0 *arg0) {
    arg0->unk1 = -1;
}
