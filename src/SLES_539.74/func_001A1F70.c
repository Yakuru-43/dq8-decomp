// range: 0x1A1F70 0x1A1FE0
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_0019B190();                         /* extern */

char *func_001A1F70(char *arg0) {
    func_0019B190(arg0 + 0x17920);
    M2C_FIELD(arg0, s32 *, 0x17910) = 0;
    M2C_FIELD(arg0, s32 *, 0x17914) = 0;
    M2C_FIELD(arg0, s32 *, 0x17918) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x1791C) = 0x3F800000;
    return arg0;
}
