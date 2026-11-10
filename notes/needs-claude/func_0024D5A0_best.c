// range: 0x24D5A0 0x24D640
// rodata: 0x3C8E50 0x3C8E6C
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 kind;
    /* 0x03 */ u8 pad_03[0x2D];
} Entry_003E0B6C; /* size 0x30 */

extern s32 *D_003E0B68;
extern Entry_003E0B6C *D_003E0B6C;

s32 func_0024D5A0(s32 arg0) {
    Entry_003E0B6C *entry;
    s32 count;
    s32 i;
    s32 kind;

    if (D_003E0B68 != 0) {
        count = *D_003E0B68;
        entry = D_003E0B6C;
        i = 0;
        while (i < count) {
            if (entry->id == arg0) {
                goto found;
            }
            i++;
            entry++;
        }
        entry = 0;
    } else {
        entry = 0;
    }
found:
    if (entry != 0) {
        kind = entry->kind;
    } else {
        kind = 0;
    }
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return 1;
    case 0:
    case 6:
    default:
        break;
    }
    return 0;
}
