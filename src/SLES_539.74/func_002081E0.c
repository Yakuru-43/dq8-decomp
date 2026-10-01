// range: 0x2081E0 0x208220
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00372AA0(char *);                      /* extern */
M2C_UNK func_00372CC0(char *);                      /* extern */

void func_002081E0(char *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x57FC) != 0) {
        func_00372AA0(arg0 + 0x57FC);
    }
    func_00372CC0(arg0 + 0x57FC);
}
