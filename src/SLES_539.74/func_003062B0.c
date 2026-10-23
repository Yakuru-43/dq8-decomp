// range: 0x3062B0 0x306340
#include "common.h"

typedef struct {
    /* 0x0 */ s16 key;
    /* 0x2 */ s16 value;
    /* 0x4 */ u8 pad[0x20];
} SearchEntry;

extern s32 D_003E1118;
extern SearchEntry *D_003E111C;

s32 func_003062B0(s32 key) {
    SearchEntry *entry;
    s32 mid;
    s32 lo;
    s32 hi;

    lo = 0;
    hi = D_003E1118 - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (D_003E111C[mid].key < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    entry = &D_003E111C[lo];
    if (key != entry->key) {
        entry = 0;
    }
    if (entry == 0) {
        return -1;
    }
    return entry->value;
}
