// range: 0x3386E0 0x3387A0
#include "common.h"

struct Entry {
    s32 key;
    u8 pad[0x1C];
};

extern struct Entry *D_003E124C;
extern s32 D_003E1254;

struct Entry *func_003386E0(s32 key) {
    struct Entry *base;
    struct Entry *e;
    s32 count;
    s32 low;
    s32 high;
    s32 mid;

    count = D_003E1254;
    low = 0;
    base = D_003E124C;
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
