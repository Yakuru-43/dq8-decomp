// range: 0x281660 0x281710
// auto: m2c draft, verified byte-exact
#include "common.h"

M2C_UNK func_00131188();       /* extern */
M2C_UNK func_00283F10(); /* extern */
M2C_UNK func_00289080();                            /* extern */

void func_00281660(char *arg0) {
    func_00289080();
    func_00131188(arg0 + 0x4F0, 0, 0x2C);
    M2C_FIELD(arg0, s32 *, 0x4F0) = -1;
    M2C_FIELD(arg0, s32 *, 0x4FC) = -1;
    M2C_FIELD(arg0, s32 *, 0x500) = -1;
    M2C_FIELD(arg0, s32 *, 0x4F8) = 1;
    M2C_FIELD(arg0, s32 *, 0x504) = 1;
    M2C_FIELD(arg0, s32 *, 0x508) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x50C) = 0;
    M2C_FIELD(arg0, s32 *, 0x510) = -1;
    M2C_FIELD(arg0, s32 *, 0x514) = 0;
    M2C_FIELD(arg0, s32 *, 0x518) = 0;
    M2C_FIELD(arg0, s32 *, 0x51C) = 0;
    M2C_FIELD(arg0, s32 *, 0x520) = 0x43200000;
    M2C_FIELD(arg0, s32 *, 0x524) = 0x44960000;
    M2C_FIELD(arg0, s32 *, 0x528) = 0;
    M2C_FIELD(arg0, s32 *, 0x52C) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x530) = 0x3F800000;
    M2C_FIELD(arg0, s32 *, 0x534) = 0;
    func_00283F10(arg0 + 0x568, 0x3F800000, 1, -1);
    M2C_FIELD(arg0, s32 *, 0x53C) = 0;
    M2C_FIELD(arg0, s8 *, 0x540) = 0;
    M2C_FIELD(arg0, s32 *, 0x544) = 0;
    M2C_FIELD(arg0, s32 *, 0x554) = 0;
}
