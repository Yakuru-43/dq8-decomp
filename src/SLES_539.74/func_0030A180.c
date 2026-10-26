// range: 0x30A180 0x30A280
#include "common.h"

struct Entry {
    s16 inUse;
    s16 ident;
    s16 state;
    s16 pad6;
    s32 logId;
    s32 fieldC;
    char *handle;
};

s32 func_0024C670(s32);                               /* extern */
s32 func_00162FB0(char *, s32, s32 *, s32, s32);      /* extern */
s32 func_00162890(char *, s32, s32 *, s32, s32);      /* extern */
s32 func_0015F450();                                   /* extern */
void func_00159810(s32, char *, s32);                    /* extern */
extern char D_003D0220[];

s32 func_0030A180(struct Entry *entry, s32 param) {
    s32 out;
    s32 offset;
    s32 result;
    char *handle;

    result = func_0024C670(entry->logId);
    if (result < 0) {
        return 0;
    }
    offset = result << 12;
    entry->inUse = 1;
    entry->handle = 0;
    if (param != 0) {
        result = func_00162FB0(D_003D0220, entry->fieldC, &out, offset,
                               0x1000);
        if (result != 0) {
            entry->state = 1;
            return 1;
        }
        entry->state = 0;
    } else {
        result = func_00162890(D_003D0220, entry->fieldC, &out, offset, 0x1000);
        if (result != 0) {
            entry->state = 2;
            return 1;
        }
        entry->state = 0;
        if (entry->inUse != 0) {
            handle = entry->handle;
            if (handle != 0) {
                func_00159810(func_0015F450(), handle + 8, entry->ident);
            }
        }
        entry->inUse = 0;
        entry->handle = 0;
        entry->state = 0;
        entry->logId = -1;
    }
    return 0;
}
