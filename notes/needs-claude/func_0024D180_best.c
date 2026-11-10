// range: 0x24D180 0x24D380
#include "common.h"

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02[0x0E];
    /* 0x10 */ u8 val[6];
    /* 0x16 */ u8 pad_16[0x1A];
} Entry_003E0B6C; /* size 0x30 */

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad_02[0x0A];
} Entry_003E0B60; /* size 0xC */

extern void func_00131188(char *, s32, s32);
extern s32 *D_003E0B68;
extern Entry_003E0B6C *D_003E0B6C;
extern Entry_003E0B60 *D_003E0B60;
extern s8 D_003DFD68[];

static inline Entry_003E0B6C *FindEntry(s32 key) {
    Entry_003E0B6C *entry;
    s32 count;
    s32 i;

    if (D_003E0B68 == 0) {
        return 0;
    }
    entry = D_003E0B6C;
    count = *D_003E0B68;
    i = 0;
    while (i < count) {
        if (entry->id == key) {
            goto found;
        }
        i++;
        entry++;
    }
    entry = 0;
found:
    return entry;
}

static inline Entry_003E0B60 *FindOther(s32 key) {
    Entry_003E0B60 *other;
    s32 count;
    s32 i;

    if (D_003E0B68 == 0) {
        return 0;
    }
    other = D_003E0B60;
    if (other == 0) {
        return 0;
    }
    count = *D_003E0B68;
    i = 0;
    while (i < count) {
        if (other->id == key) {
            goto found;
        }
        i++;
        other++;
    }
    other = 0;
found:
    return other;
}

static inline void StoreResult(s32 *out, s32 *local) {
    s32 *src;
    s32 *dst;
    s32 n;

    out[0] = local[0];
    src = &local[1];
    dst = &out[1];
    for (n = 3; n > 0; n--) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst += 2;
        src += 2;
    }
    out[7] = local[7];
    out[8] = local[8];
}

void func_0024D180(s32 *out, s32 key) {
    s32 local[9];
    Entry_003E0B6C *entry;
    Entry_003E0B60 *other;
    s32 i;

    func_00131188((char *)local, 0, 36);
    local[0] = 0;
    entry = FindEntry(key);
    if (entry != 0) {
        local[1] = entry->val[0];
        local[2] = entry->val[1];
        local[3] = entry->val[2];
        local[4] = entry->val[3];
        local[5] = entry->val[4];
        local[6] = entry->val[5];
        other = FindOther(key);
        if (other != 0) {
            if (key == 0x23) {
                local[0] = 5;
            }
        }
        for (i = 0; i < 4; i++) {
            if (local[8] < local[i + 1]) {
                local[8] = local[i + 1];
                local[0] = D_003DFD68[i];
            }
        }
        StoreResult(out, local);
        return;
    }
    StoreResult(out, local);
}
