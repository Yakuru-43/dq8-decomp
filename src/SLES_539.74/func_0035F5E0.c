// range: 0x35F5E0 0x35F620
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001575A0(char *);                      /* extern */

char *func_0035F5E0(char *arg0) {
    M2C_FIELD(arg0, s32 *, 0x394) = 0;
    M2C_FIELD(arg0, s32 *, 0x390) = -1;
    func_001575A0(arg0 + 0x390);
    return arg0;
}
