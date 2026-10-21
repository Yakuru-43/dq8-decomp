// range: 0x467060 0x467070
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x8];
    s32 unk8;
} S_arg0;

void func_00467060(S_arg0 *arg0, s32 arg1) {
    arg0->unk8 = arg1;
}
