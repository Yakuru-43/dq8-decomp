// range: 0x281CA0 0x281CB0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2C];
    s32 unk2C;
} S_arg1;

s32 func_00281CA0(s32 arg0, S_arg1 *arg1) {
    arg1->unk2C = -1;
    return 1;
}
