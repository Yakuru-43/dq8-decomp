// range: 0x1EF250 0x1EF2A0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_001EED90();                            /* extern */
M2C_UNK func_001EF2A0();                      /* extern */
M2C_UNK func_001F2260();                         /* extern */
M2C_UNK func_001F9850();                      /* extern */
extern M2C_UNK D_003DDF30 __attribute__((section(".data")));

char *func_001EF250(char *arg0) {
    func_001EED90();
    M2C_FIELD(arg0, M2C_UNK **, 0x68) = &D_003DDF30;
    func_001F2260(arg0 + 0x114);
    func_001EF2A0(arg0 + 0x148);
    func_001F9850(arg0);
    return arg0;
}
