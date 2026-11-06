// range: 0x16E080 0x16E130
// best attempt (Qwen, factory-1, 2026-11-05): 9 words differ, CLASS reorder+register score=9
#include "common.h"

void func_0016E080(char *table, s32 *list) {
    s32 *rec;
    s32 i;
    s32 type;
    s32 idx;
    s32 val;
    s32 flags;
    char *base;

    if (list == 0) {
        return;
    }
    rec = list + 4;
    for (i = 0; i < list[0]; i++) {
        type = *rec;
        if (type == 0) {
            idx = rec[1];
            val = rec[2];
            flags = rec[3];
            if (idx >= 0 && idx < 0x80) {
                base = table + idx * 8;
                M2C_FIELD(base, s32 *, 0x10) = 0;
                M2C_FIELD(base, s32 *, 0x14) = flags | val;
            }
        } else if (type == 1) {
            idx = rec[1];
            flags = rec[3];
            if (idx >= 0 && idx < 0x20) {
                base = table + idx * 8;
                M2C_FIELD(base, s32 *, 0x414) = flags;
                M2C_FIELD(base, s32 *, 0x410) = 0;
            }
        }
        rec += 4;
    }
}
