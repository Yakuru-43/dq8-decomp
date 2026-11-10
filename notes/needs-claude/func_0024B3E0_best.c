// range: 0x24B3E0 0x24B550
#include "common.h"

typedef struct Entry_0024B3E0 {
    /* 0x00 */ s16 f0;
    /* 0x02 */ s16 keys[3];
    /* 0x08 */ u8 pad[0x20];
} Entry_0024B3E0; /* size 0x28 */

typedef struct Bag_0024B3E0 {
    /* 0x00 */ u8 pad[0x20];
    /* 0x20 */ s32 count;
    /* 0x24 */ Entry_0024B3E0 entries[1];
} Bag_0024B3E0;

Entry_0024B3E0 *func_0024B3E0(Bag_0024B3E0 *bag, s32 *keys, s32 mode) {
    Entry_0024B3E0 *base;
    Entry_0024B3E0 *f;
    s32 used[3];
    s32 i;
    s32 ok;
    s32 j;
    s32 k;

    base = bag->entries;
    for (i = 0; i < bag->count; i++) {
        f = &base[i];
        if (f->keys[0] == 0) {
            continue;
        }
        if (f->keys[1] == 0) {
            continue;
        }
        if (mode == 3) {
            if (f->keys[2] == 0) {
                continue;
            }
        }
        if (mode == 2) {
            if (f->keys[2] != 0) {
                continue;
            }
        }
        used[0] = 0;
        used[1] = 0;
        used[2] = 0;
        ok = 1;
        for (j = 0; j < mode; j++) {
            s16 v = f->keys[j];
            if (v == 0) {
                break;
            }
            for (k = 0; k < 3; k++) {
                if (used[k] == 0 && keys[k] == v) {
                    used[k] = 1;
                    break;
                }
            }
            if (k == 3) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            break;
        }
    }
    f = &bag->entries[i];
    if (f->f0 == 0) {
        ok = 0;
    }
    if (ok == 1) {
        return f;
    }
    return 0;
}
