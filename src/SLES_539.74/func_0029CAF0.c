// range: 0x29CAF0 0x29CB00
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x10];
    s16 unk10;
} S_arg1;

s32 func_0029CAF0(s32 arg0, S_arg1 *arg1) {
    return arg1->unk10 != 0;
}
