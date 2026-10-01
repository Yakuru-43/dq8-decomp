// range: 0x4606B0 0x4606D0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x38];
    f32 unk38;
    f32 unk3C;
} S_arg0;

void func_004606B0(S_arg0 *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = arg0->unk38;
    *arg2 = arg0->unk3C;
}
