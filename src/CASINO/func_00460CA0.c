// range: 0x460CA0 0x460CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1668];
    s32 unk1668;
} S_arg0;

void func_00460CA0(S_arg0 *arg0, s32 arg1) {
    arg0->unk1668 = arg1;
}
