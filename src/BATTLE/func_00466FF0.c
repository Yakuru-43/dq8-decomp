// range: 0x466FF0 0x467000
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4CC];
    f32 unk4CC;
} S_arg0;

f32 func_00466FF0(S_arg0 *arg0) {
    return arg0->unk4CC;
}
