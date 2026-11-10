// range: 0x140B00 0x140DC4
#include "common.h"

s32 *func_0014E130(s32, s32);
s32 func_0014E360(s32, s32, s32, s32);
void func_00142DE0(void *);

typedef struct Src {
    /* 0000 */ char pad_0[0xC];
    /* 000C */ s32 count;
} Src;

typedef struct Table {
    /* 0000 */ char pad_0[0x3B90];
    /* 3B90 */ Src *src;
    /* 3B94 */ s32 pool;
    /* 3B98 */ s32 h98;
    /* 3B9C */ s32 h9C;
    /* 3BA0 */ s32 *q;
    /* 3BA4 */ s32 count;
    /* 3BA8 */ s32 *p;
    /* 3BAC */ s32 num;
    /* 3BB0 */ s32 *f0;
    /* 3BB4 */ s32 *f4;
    /* 3BB8 */ s32 *f8;
    /* 3BBC */ s32 *fc;
    /* 3BC0 */ s32 size;
    /* 3BC4 */ s32 max;
} Table;

void func_00140B00(Table *t, s32 pool, s32 *list, s32 n3) {
    Src *src;
    s32 *p;
    s32 *p0;
    s32 *p3;
    s32 *p4;
    s32 i;
    s32 n;
    u32 bytes;
    s32 blocks;
    s32 count;

    src = t->src;
    t->pool = 0;
    if (pool == 0) {
        return;
    }
    if (src == 0) {
        return;
    }
    t->h98 = func_0014E360(pool, 2, 0, 0x40);
    if (t->h98 == 0) {
        return;
    }
    func_00142DE0(t);
    t->pool = pool;
    pool = t->pool;
    t->count = src->count;
    t->num = t->count;
    t->q = 0;
    t->p = 0;
    bytes = t->num * 4;
    blocks = bytes >> 4;
    count = blocks + 1;
    if (list != 0) {
        bytes = t->count * 4;
        if (bytes & 0xF) {
            blocks = (bytes >> 4) + 1;
        } else {
            blocks = bytes >> 4;
        }
        t->p = func_0014E130(pool, blocks);
        i = 0;
        while (i < t->count) {
            t->p[i] = -1;
            i++;
        }
        p = list;
        n = 0;
        while (*p >= 0) {
            n++;
            p++;
        }
        bytes = (n + 1) * 4;
        if (bytes & 0xF) {
            blocks = (bytes >> 4) + 1;
        } else {
            blocks = bytes >> 4;
        }
        t->q = func_0014E130(pool, blocks);
        i = 0;
        while (i < n) {
            t->q[i] = list[i];
            t->p[t->q[i]] = i;
            i++;
        }
        t->q[i] = -1;
        t->num = n;
        bytes = t->num * 4;
        blocks = bytes >> 4;
        count = blocks + 1;
    }
    t->f0 = func_0014E130(pool, count);
    t->f4 = func_0014E130(pool, count);
    t->f8 = func_0014E130(pool, count);
    t->size = n3;
    t->max = t->size - 1;
    bytes = t->size * 4;
    if (bytes & 0xF) {
        blocks = (bytes >> 4) + 1;
    } else {
        blocks = bytes >> 4;
    }
    t->fc = func_0014E130(pool, blocks);
    p0 = t->f0;
    p3 = t->f8;
    p4 = t->fc;
    i = 0;
    while (i < t->num) {
        *p0++ = 0;
        *p3++ = 0;
        i++;
    }
    i = 0;
    while (i < t->size) {
        *p4++ = 0;
        i++;
    }
    t->h9C = 0;
}
