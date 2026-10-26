// range: 0x13F010 0x13F060
#include "common.h"

void *func_0014E130(s32, M2C_UNK);                  /* extern */

void func_0013F010(void *arg0) {
    if (M2C_FIELD(arg0, s32 *, 0xE8) != 0) {
        return;
    }
    func_0014E130(M2C_FIELD(arg0, s32 *, 0),
        (M2C_FIELD(arg0, char **, 0xF4) - M2C_FIELD(arg0, char **, 0xEC)) / 16);
}
