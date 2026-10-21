// range: 0x471410 0x471420
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x500];
    s32 unk500;
} S_arg0;

s32 func_00471410(S_arg0 *arg0) {
    return arg0->unk500;
}
