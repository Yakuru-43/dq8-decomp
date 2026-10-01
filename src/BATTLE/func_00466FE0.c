// range: 0x466FE0 0x466FF0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4C8];
    f32 unk4C8;
} S_arg0;

f32 func_00466FE0(S_arg0 *arg0) {
    return arg0->unk4C8;
}
