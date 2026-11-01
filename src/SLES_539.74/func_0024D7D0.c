// range: 0x24D7D0 0x24D840
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02;
    /* 0x03 */ u8 kind;
    /* 0x04 */ u8 pad_04[0x2C];
} Entry_003E0B6C; /* size 0x30 */

extern s32 *D_003E0B68;
extern Entry_003E0B6C *D_003E0B6C;

static inline Entry_003E0B6C *FindEntry(s32 key) {
    Entry_003E0B6C *entry;
    s32 count;
    s32 i;

    if (D_003E0B68 == 0) {
        return 0;
    }
    count = *D_003E0B68;
    entry = D_003E0B6C;
    i = 0;
    while (i < count) {
        if (entry->id == key) {
            return entry;
        }
        i++;
        entry++;
    }
    return 0;
}

s32 func_0024D7D0(s32 key) {
    Entry_003E0B6C *entry = FindEntry(key);
    if (entry != 0) {
        return entry->kind;
    }
    return 0;
}
