// range: 0x20CF90 0x20D0A0
#include "common.h"

M2C_UNK func_0014DF10(char *, char *, M2C_UNK);     /* extern */
M2C_UNK func_001746D0(M2C_UNK);                     /* extern */
M2C_UNK func_00176500(M2C_UNK);                     /* extern */

void func_0020CF90(char *arg0) {
    char *obj;
    char *base;
    char *entry;
    s32 i;
    s32 j;

    obj = arg0;
    func_001746D0(4);
    func_001746D0(1);
    for (i = 0; i < 16; i++) {
        base = obj + (i << 2);
        M2C_FIELD(base, s32 *, 0x5878) = -1;
        M2C_FIELD(base, s32 *, 0x58B8) = -1;
    }
    func_0014DF10(obj + 0x5D00, obj + 0x5900, 0x40);
    func_00176500(4);
    func_00176500(1);
    for (i = 0; i < 4; i++) {
        base = obj + (i << 2);
        M2C_FIELD(base, s32 *, 0x5F78) = -1;
        M2C_FIELD(base, s32 *, 0x5F88) = 0;
    }
    entry = obj + 0x5D58;
    for (i = 0; i < 4; i++) {
        *(s32 *)entry = -1;
        *(s32 *)(entry + 4) = 0;
        for (j = 0; j < 16; j++) {
            *(s32 *)(entry + (j << 2) + 8) = 0;
            *(s32 *)(entry + (j << 2) + 0x48) = 0;
        }
        entry += 0x88;
    }
    entry = obj + 0x5D58;
    for (i = 0; i < 4; i++) {
        *(s32 *)entry = -1;
        *(s32 *)(entry + 4) = 0;
        entry += 0x88;
    }
}
