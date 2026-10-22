// range: 0x20D110 0x20D300
#include "common.h"

M2C_UNK func_0014DF10(char *, char *, M2C_UNK);      /* extern */
M2C_UNK func_001746D0(M2C_UNK);                     /* extern */
M2C_UNK func_00176500(M2C_UNK);                     /* extern */
M2C_UNK func_001709B0();                             /* extern */
M2C_UNK func_001709D0(char *, M2C_UNK, char *);      /* extern */
M2C_UNK func_00170950();                             /* extern */
M2C_UNK func_00266240();                             /* extern */
M2C_UNK func_00306290(char *);                       /* extern */
void func_0020CF90(char *);                          /* extern */

void func_0020D110(void *arg0) {
    char *obj;
    char *src;
    s32 count;
    s32 k;

    obj = arg0;
    M2C_FIELD(obj, s32 *, 0x6410) = -1;
    M2C_FIELD(obj, s32 *, 0x6414) = -1;
    src = *(char **)(obj + 0x6418);
    if (src != 0) {
        func_0014DF10(obj + 0x641C, src, 0x180);
    } else {
        func_0014DF10(obj + 0x641C, 0, 0);
    }
    func_001746D0(3);
    func_00176500(3);
    func_001746D0(9);
    M2C_FIELD(obj, s32 *, 0x6474) = -1;
    M2C_FIELD(obj, s32 *, 0x6478) = -1;
    src = *(char **)(obj + 0x647C);
    if (src != 0) {
        func_0014DF10(obj + 0x6480, src, 0x38C);
    } else {
        func_0014DF10(obj + 0x6480, 0, 0);
    }
    func_00176500(9);
    func_001746D0(2);
    func_0020CF90(obj);
    M2C_FIELD(obj, s32 *, 0x5F98) = -1;
    M2C_FIELD(obj, s32 *, 0x5F9C) = -1;
    func_0014DF10(obj + 0x63A0, obj + 0x5FA0, 0x40);
    func_00176500(2);
    M2C_FIELD(obj, s32 *, 0x6400) = 0;
    M2C_FIELD(obj, s32 *, 0x63F8) = 0;
    M2C_FIELD(obj, s32 *, 0x6404) = 0x3F800000;
    M2C_FIELD(obj, s32 *, 0x63FC) = -1;
    M2C_FIELD(obj, s32 *, 0x6408) = 0;
    M2C_FIELD(obj, s32 *, 0x640C) = 0;
    func_0020CF90(obj);
    func_0014DF10(obj + 0x64F8, *(char **)(obj + 0x64F4), 0x200);
    func_001709B0(obj + 0x6550);
    count = *(s32 *)(obj + 0x64F4);
    if (count != 0) {
        func_001709D0(obj + 0x6550, 0x30, obj + 0x64F8);
        func_00170950(obj + 0x6550);
    }
    M2C_FIELD(obj, s32 *, 0x55F0) = -1;
    M2C_FIELD(obj, u8 *, 0x55F5) = 0;
    M2C_FIELD(obj, u8 *, 0x55F6) = 0;
    M2C_FIELD(obj, s32 *, 0x5604) = -1;
    M2C_FIELD(obj, s32 *, 0x5608) = -1;
    M2C_FIELD(obj, u8 *, 0x55FC) = 0;
    M2C_FIELD(obj, s32 *, 0x5600) = 0x3F800000;
    M2C_FIELD(obj, s32 *, 0x64D8) = -1;
    for (k = 0; k < 2; k++) {
        M2C_FIELD(obj + (k << 2), s32 *, 0x64DC) = -1;
        M2C_FIELD(obj + (k << 2), s32 *, 0x64E4) = -1;
    }
    func_001746D0(8);
    func_00176500(8);
    M2C_FIELD(obj, s32 *, 0x64F0) = 0;
    func_00266240(obj + 0x655C);
    for (k = 0; k < 16; k++) {
        func_00306290(obj + k * 0xC + 0x67F4);
    }
}
