// range: 0x467730 0x467750
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2E];
    s16 unk2E;
} S_arg0;

void func_00467730(S_arg0 *arg0, f32 fparg0) {
    arg0->unk2E = M2C_BITWISE(s16, (16384.0f * fparg0));
}
