// range: 0x468C00 0x468C10
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4DC];
    s32 unk4DC;
} S_arg0;

s32 func_00468C00(S_arg0 *arg0) {
    return arg0->unk4DC;
}
