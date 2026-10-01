// range: 0x45EE70 0x45EE80
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x578];
    s32 unk578;
} S_arg0;

s32 func_0045EE70(S_arg0 *arg0) {
    return arg0->unk578;
}
