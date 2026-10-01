// range: 0x2224F0 0x2225E0
// auto: m2c, verified byte-exact
#include "common.h"

M2C_UNK func_00221CF0(void *);                      /* extern */
M2C_UNK func_00222320(void *, M2C_UNK);             /* extern */
M2C_UNK func_00222370(void *, M2C_UNK);             /* extern */
M2C_UNK func_002223C0(void *, M2C_UNK);             /* extern */
M2C_UNK func_002224D0(void *, M2C_UNK);             /* extern */
M2C_UNK func_002225E0();                            /* extern */
M2C_UNK func_002E5810(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F5E90(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F5F70(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F5F80(void *, M2C_UNK);             /* extern */
M2C_UNK func_002F6340(void *, M2C_UNK);             /* extern */

void func_002224F0(void *arg0) {
    func_002225E0();
    func_002F6340(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0xE4) = 4;
    M2C_FIELD(arg0, s8 *, 0x11D4) = 0;
    func_00222320(arg0, 0);
    M2C_FIELD(arg0, s8 *, 0x1F28) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F2A) = 1;
    M2C_FIELD(arg0, s8 *, 0x1F2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x1F36) = 2;
    M2C_FIELD(arg0, s32 *, 0x1F38) = -1;
    M2C_FIELD(arg0, s8 *, 0x1639) = -1;
    func_002E5810(arg0, 1);
    func_00221CF0(arg0);
    func_00222370(arg0, 0);
    M2C_FIELD(arg0, s32 *, 0x1F40) = -1;
    M2C_FIELD(arg0, s32 *, 0x1F3C) = -1;
    M2C_FIELD(arg0, s16 *, 0x1F34) = -1;
    func_002223C0(arg0, 1);
    func_002224D0(arg0, 1);
    func_002F5F80(arg0, 0);
    func_002F5F70(arg0, 1);
    M2C_FIELD(arg0, s8 *, 0x1611) = 1;
    M2C_FIELD(arg0, s32 *, 0xFC) = 0x19;
    func_002F5E90(arg0, 1);
    M2C_FIELD(arg0, s32 *, 0x1F30) = 0;
}
