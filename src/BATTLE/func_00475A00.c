// range: 0x475A00 0x475A10
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x578];
    s32 unk578;
} S_arg0;

s32 func_00475A00(S_arg0 *arg0) {
    return arg0->unk578;
}
