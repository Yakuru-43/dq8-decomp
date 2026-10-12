// range: 0x28EDC0 0x28EDF0
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_0028EDC0(char *arg0, s128 *arg1) {
    M2C_FIELD(arg0, s128 *, 0xE0) = (s128) *arg1;
    if (M2C_FIELD(arg0, s32 *, 0x290) == 0) {
        M2C_FIELD(arg0, s128 *, 0x50) = (s128) *arg1;
    }
}
