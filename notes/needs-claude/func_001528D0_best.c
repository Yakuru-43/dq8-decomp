// range: 0x1528D0 0x152970
// NOT MATCHED (156/160, CLASS structural score=33) — draft only, see the .md
#include "common.h"

extern s32 func_001537A0(char *table, s32 index);

typedef struct EntryVal {
    s32 pad0;
    s32 value;
} EntryVal;

s32 func_001528D0(char *ctx, char *out, s32 key, char *owner) {
    char *e;
    EntryVal *val;
    s32 value;
    void *rec;

    if (owner == 0) {
        owner = ctx + 0x120;
    }
    rec = 0;
    if (owner != 0) {
        e = *(char **)(owner + 0x44);
        while (e != 0) {
            if (*(s32 *)(e + 0x14) == key) {
                break;
            }
            e = *(char **)e;
        }
        if (e != 0) {
            val = (EntryVal *)(e + 0x10);
            value = val->value;
        } else {
            value = -1;
        }
        rec = (void *)*(s32 *)owner;
        if (rec == 0) {
            rec = 0;
        } else {
            rec = (void *)func_001537A0(*(char **)(owner + 0xC), value);
        }
    }
    if (rec == 0) {
        return 0;
    }
    *(u128 *)out = *(u128 *)((char *)rec + 0x20);
    *(u128 *)(out + 0x10) = *(u128 *)((char *)rec + 0x30);
    return 1;
}
