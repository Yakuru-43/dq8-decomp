// range: 0x18A310 0x18A340
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001E05D0(u8, u8, u8);                  /* extern */

void func_0018A310(char *arg0) {

    if (!(M2C_FIELD(arg0, s8 *, 0x68CC) != 0)) {
        return;
    }

    func_001E05D0(M2C_FIELD(arg0, u8 *, 0x68CD), M2C_FIELD(arg0, u8 *, 0x68CE), M2C_FIELD(arg0, u8 *, 0x68CF));
}
