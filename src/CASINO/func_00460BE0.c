// range: 0x460BE0 0x460BF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x11D4];
    s8 unk11D4;
} S_arg0;

void func_00460BE0(S_arg0 *arg0, s8 arg1) {
    arg0->unk11D4 = arg1;
}
