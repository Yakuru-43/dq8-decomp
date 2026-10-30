// range: 0x338080 0x338150
#include "common.h"

struct Entry {
    s32 key;
    u8 pad[0x10];
};

extern struct Entry *D_003E125C;
extern s32 D_003E1264;

struct Entry *func_00338080(s32 key) {
    struct Entry *base;
    struct Entry *e;
    s32 count;
    s32 low;
    s32 high;
    s32 mid;

    count = D_003E1264;
    low = 0;
    base = D_003E125C;
    high = count - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (base != 0) {
            if (mid >= 0 || count > mid) {
                e = &base[mid];
            } else {
                e = 0;
            }
        } else {
            e = 0;
        }
        if (e->key < key) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    if (base != 0) {
        if (low >= 0 || count > low) {
            e = &base[low];
        } else {
            e = 0;
        }
    } else {
        e = 0;
    }
    if (e != 0) {
        if (e->key == key) {
            return e;
        }
    }
    return 0;
}
