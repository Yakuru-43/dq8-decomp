// range: 0x476CD0 0x476CF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x28];
    s32 unk28;
    s32 unk2C;
} S_arg0;

s32 func_00476CD0(S_arg0 *arg0) {
    return arg0->unk28 + (arg0->unk2C * 0x10);
}
