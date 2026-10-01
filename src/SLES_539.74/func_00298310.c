// range: 0x298310 0x298320
// auto: m2c draft, verified byte-exact
#include "common.h"

void func_00298310(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0x488) = (s32) (arg0 + 0x448);
}
