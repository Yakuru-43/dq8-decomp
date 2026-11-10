// range: 0x19F330 0x19F470
// flags: -flag divbyzerocheck
// (the original guards the divides with bnez + break 0, 7)
#include "common.h"

typedef struct {
    /* 0x00 */ s64 q0;
    /* 0x08 */ s64 q1;
    /* 0x10 */ s32 m10;
    /* 0x14 */ s32 m14;
} PoolEntry;

typedef struct {
    /* 0x00 */ u8 pad00[8];
    /* 0x08 */ s32 m08;
    /* 0x0C */ u8 pad0C[0x44];
    /* 0x50 */ PoolEntry *entries;
    /* 0x54 */ s32 m54;
    /* 0x58 */ s32 count;
    /* 0x5C */ s32 m5C;
} Pool;

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ s32 m10;
    /* 0x14 */ s32 m14;
} Range;

s32 func_0019F330(Pool *o, Range *a) {
    s32 count;
    s32 total;
    s32 idx;
    s32 m;
    s32 ok;
    PoolEntry *e;
    s32 t;
    s32 d;
    s32 n;

    count = o->count;
    total = o->m54;
    idx = (o->m5C - count + total) % total;
    m = o->m08 << 11;
    ok = 1;
    if (count <= 0) {
        return 0;
    }
    while (ok) {
        e = &o->entries[idx];
        if (e->m14 == 0) {
            break;
        }
        if (a->m14 == 0) {
            break;
        }
        t = (e->m10 + m - a->m10) % m;
        if (t < a->m14) {
            d = e->m14;
            t = a->m10 + a->m14 - e->m10;
            if (d >= t) {
                d = t;
            }
            e->m10 = (e->m10 + d) % m;
            e->m14 = e->m14 - d;
            if (e->m14 == 0) {
                if (e->q0 >= 0) {
                    e->q0 = -1;
                    e->q1 = -1;
                    e->m10 = 0;
                    e->m14 = 0;
                }
                n = o->count - 1;
                if (n < 0) {
                    n = 0;
                }
                o->count = n;
            }
        } else {
            ok = 0;
        }
        idx = (idx + 1) % o->m54;
    }
    return 0;
}
