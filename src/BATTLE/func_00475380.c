// range: 0x475380 0x4753B0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x2E];
    s16 unk2E;
} S_arg0;

f32 func_00475380(S_arg0 *arg0) {
    return (f32) arg0->unk2E / 16384.0f;
}
