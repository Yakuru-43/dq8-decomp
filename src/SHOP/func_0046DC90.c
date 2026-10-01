// range: 0x46DC90 0x46DCA0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x28];
    s32 unk28;
} S_arg0;

s32 func_0046DC90(S_arg0 *arg0) {
    return arg0->unk28;
}
