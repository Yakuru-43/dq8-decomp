// range: 0x467210 0x467250
// auto: m2c draft, verified byte-exact
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_132D38();

s32 func_00467210(s32 n) {
    return func_132D38() % n;
}
