// range: 0x24CEF0 0x24CF90
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02;
    /* 0x03 */ u8 kind;
    /* 0x04 */ u8 pad_04[4];
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8 pad_0A[0x18];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ u8 pad_26[0xA];
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

s16 func_0024CEF0(s32 arg0, s32 arg1) {
    Entry_003E0B6C *entry;

    entry = FindEntry(arg0);
    if (entry == 0) {
        return -1;
    }
    if (arg1 == 0) {
        return entry->unk22;
    }
    if (arg1 == 1) {
        return entry->unk24;
    }
    if (arg1 == 2) {
        return entry->unk08;
    }
    return -1;
}
