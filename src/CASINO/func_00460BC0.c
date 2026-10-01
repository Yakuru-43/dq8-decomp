// range: 0x460BC0 0x460BD0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x1624];
    s32 unk1624;
} S_arg0;

s32 func_00460BC0(S_arg0 *arg0) {
    return arg0->unk1624;
}
