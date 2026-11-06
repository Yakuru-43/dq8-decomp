// range: 0x24DA90 0x24DB60
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02[0x06];
    /* 0x08 */ s16 field_08;
    /* 0x0A */ u8 pad_0A[0x18];
    /* 0x22 */ s16 field_22;
    /* 0x24 */ s16 field_24;
    /* 0x26 */ u8 pad_26[0x0A];
} Entry_003E0B6C; /* size 0x30 */

extern s32 *D_003E0B68;
extern Entry_003E0B6C *D_003E0B6C;

s32 func_0024DA90(s32 key, s32 sel) {
    Entry_003E0B6C *entry;
    s32 count;
    s32 i;

    if (D_003E0B68 == 0) {
        return 0;
    }
    entry = D_003E0B6C;
    if (sel == 0) {
        count = *D_003E0B68;
        i = 0;
        while (i < count) {
            if (entry->field_22 == key) {
                return entry->id;
            }
            i++;
            entry++;
        }
    } else if (sel == 1) {
        count = *D_003E0B68;
        i = 0;
        while (i < count) {
            if (entry->field_24 == key) {
                return entry->id;
            }
            i++;
            entry++;
        }
    } else if (sel == 2) {
        count = *D_003E0B68;
        i = 0;
        while (i < count) {
            if (entry->field_08 == key) {
                return entry->id;
            }
            i++;
            entry++;
        }
    }
    return 0;
}
