// range: 0x20CC70 0x20CDA0
#include "common.h"

void func_003727A0(char *);                          /* extern */
M2C_UNK func_00306170();                             /* extern */
M2C_UNK func_0014DF10();                             /* extern */
M2C_UNK func_00176500(M2C_UNK);                      /* extern */
M2C_UNK func_00175B20(M2C_UNK);                      /* extern */
M2C_UNK func_001709B0();                             /* extern */
M2C_UNK func_001709D0(char *, M2C_UNK, char *);      /* extern */
M2C_UNK func_00170950();                             /* extern */

void func_0020CC70(void *arg0) {
    char *obj;
    char *slot;
    char *entry;
    s32 idx;
    s32 count;

    obj = arg0;
    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = obj + idx * 0xC0 + 0x5610;
    }
    if (idx < 0) {
        entry = 0;
    } else {
        entry = obj + idx * 0x6C + 0x5790;
    }
    if (entry != 0) {
        func_003727A0(entry);
    }
    M2C_FIELD(slot, s32 *, 0x28) = -1;
    M2C_FIELD(slot, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(slot, s32 *, 0x20) = 0;
    idx = M2C_FIELD(obj, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = obj + idx * 0xC0 + 0x5610;
    }
    func_00306170(slot);
    func_0014DF10(slot + 0x60, slot + 0x40, 2);
    func_00176500(M2C_FIELD(slot, s32 *, 0));
    slot = obj;
    func_00175B20(-1);
    func_0014DF10(obj + 0x64F8, *((s32 *)(slot + 0x64F4)), 0x200);
    func_001709B0(obj + 0x6550);
    count = *((s32 *)(slot + 0x64F4));
    if (count != 0) {
        func_001709D0(obj + 0x6550, 0x30, obj + 0x64F8);
        func_00170950(obj + 0x6550);
    }
}
