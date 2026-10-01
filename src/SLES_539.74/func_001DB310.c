// range: 0x1DB310 0x1DB340
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x54];
    s32 unk54;
} S_arg0;

s32 func_001DB310(S_arg0 *arg0, s32 arg1, s32 arg2) {
    if ((arg0->unk54 >= 0) && (arg2 == 0)) {
        return -1;
    }
    arg0->unk54 = arg1;
    return 0;
}
