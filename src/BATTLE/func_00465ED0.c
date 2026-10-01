// range: 0x465ED0 0x465EE0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1];
    s8 unk1;
} S_arg0;

void func_00465ED0(S_arg0 *arg0) {
    arg0->unk1 = -1;
}
