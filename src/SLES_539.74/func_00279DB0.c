// range: 0x279DB0 0x279DE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_001814D0();                                /* extern */
s32 func_00191EB0(s32);                             /* extern */
M2C_UNK func_003089E0(s32, M2C_UNK);                /* extern */

void func_00279DB0(void) {
    func_003089E0(func_00191EB0(func_001814D0()), 0xB6);
}
