// range: 0x464210 0x464220
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0xF20];
    s32 unkF20;
} S_arg0;

s32 func_00464210(S_arg0 *arg0) {
    return arg0->unkF20;
}
