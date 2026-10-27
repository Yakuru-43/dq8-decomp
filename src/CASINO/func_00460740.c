// range: 0x460740 0x460750
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x50];
    s32 unk50;
} S_arg0;

void func_00460740(S_arg0 *arg0, s32 arg1) {
    arg0->unk50 = arg1;
}
