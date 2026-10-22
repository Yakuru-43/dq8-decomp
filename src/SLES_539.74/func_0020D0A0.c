// range: 0x20D0A0 0x20D100
#include "common.h"

M2C_UNK func_00306170();                             /* extern */
M2C_UNK func_0014DF10(char *, char *, M2C_UNK);      /* extern */
M2C_UNK func_00176500(M2C_UNK);                      /* extern */

void func_0020D0A0(void *arg0) {
    char *obj;
    char *slot;
    s32 idx;

    obj = arg0;
    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = obj + idx * 0xC0 + 0x5610;
    }
    func_00306170(slot);
    func_0014DF10(slot + 0x60, slot + 0x40, 2);
    func_00176500(M2C_FIELD(slot, s32 *, 0));
}
