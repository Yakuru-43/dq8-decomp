// range: 0x20C3E0 0x20C460
#include "common.h"

void func_003727A0(char *);                          /* extern */

void func_0020C3E0(char *arg0) {
    char *slot;
    char *entry;
    s32 idx;

    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = arg0 + idx * 0xC0 + 0x5610;
    }
    if (M2C_FIELD(slot, s32 *, 0x28) >= 0) {
        if (idx < 0) {
            entry = 0;
        } else {
            entry = arg0 + idx * 0x6C + 0x5790;
        }
        func_003727A0(entry);
    }
}
