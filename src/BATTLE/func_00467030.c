// range: 0x467030 0x467040
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4CC];
    f32 unk4CC;
} S_arg0;

f32 func_00467030(S_arg0 *arg0) {
    return arg0->unk4CC;
}
