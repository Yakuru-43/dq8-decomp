// range: 0x20C2D0 0x20C360
#include "common.h"

void func_003727A0(char *);                         /* extern */

void func_0020C2D0(char *arg0) {
    char *table;
    char *entry;
    s32 idx;

    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        table = 0;
    } else {
        table = arg0 + idx * 0xC0 + 0x5610;
    }
    if (idx < 0) {
        entry = 0;
    } else {
        entry = arg0 + idx * 0x6C + 0x5790;
    }
    if (entry != 0) {
        func_003727A0(entry);
    }
    M2C_FIELD(table, s32 *, 0x28) = -1;
    M2C_FIELD(table, f32 *, 0x1C) = 1.0f;
    M2C_FIELD(table, s32 *, 0x20) = 0;
}
