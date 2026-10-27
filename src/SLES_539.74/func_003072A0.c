// range: 0x3072A0 0x307460
#include "common.h"

typedef struct {
    /* 0x0 */ void *key;
    /* 0x4 */ s16 valHi;
    /* 0x6 */ s16 valLo;
} Row;

typedef struct {
    /* 0x0 */ s16 key;
    /* 0x2 */ s16 value;
    /* 0x4 */ u8 pad[0x20];
} SearchEntry;

extern Row D_003AD080[];
extern s32 D_003E1118;
extern SearchEntry *D_003E111C;

u32 func_0018F230(s32, s32 *);
s32 func_00134598(u32, void *, s32);
s32 func_0018F2E0(s32);

static inline s32 getKind(s32 key) {
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
    if (entry != 0) {
        return entry->value;
    }
    return -1;
}

s32 func_003072A0(s32 arg0, s32 *out, f32 f) {
    u32 obj;
    s32 i;
    void *key;
    s32 kind;

    obj = func_0018F230(arg0, 0);
    if (obj == 0) {
        return 0;
    }
    for (i = 0;; i++) {
        key = D_003AD080[i].key;
        if (key == 0) {
            return 0;
        }
        if (func_00134598(obj, key, 3) != 0) {
            continue;
        }
        kind = getKind(func_0018F2E0(arg0));
        if (kind == 12 || kind == 16 || kind == 15) {
            continue;
        }
        if (out != 0) {
            if (6.0f <= f && f < 18.0f) {
                *out = D_003AD080[i].valHi;
            } else {
                *out = D_003AD080[i].valLo;
            }
        }
        return 1;
    }
}
