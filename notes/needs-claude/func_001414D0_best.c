// range: 0x1414D0 0x141750
// BEST ATTEMPT 2026-11-03 factory-1: CLASS structural score=136 (640 vs 632).
// Changes vs 2026-10-27 draft (141@648): plain params 5-7 (no param_reg, see
// notes/idioms.md "parameters 5 to 7" — mwccps2 reads $t0/$t1/$t2 without the
// attribute); call args kept in val30/val40 locals instead of rereading
// q->f40/q->f30.
#include "common.h"

s32 func_0014E130(char *, s32, u64, u64); /* extern */
extern u128 D_003A0C40;

typedef struct {
    s32 count;    /* 0x00 */
    char *cursor; /* 0x04 */
    s32 link[1];  /* 0x08 */
} Draw;

typedef struct {
    char *base; /* 0x28 */
    s32 count;  /* 0x2C */
} Buf;

typedef struct {
    s32 f0; /* 0x00 */
    s32 f4; /* 0x04 */
    s32 f8; /* 0x08 */
    s32 fC; /* 0x0C */
} Range;

union Rect {
    u64 q;
    u16 w[4];
};

union Tag {
    u128 q;
    u32 w[4];
};

typedef struct {
    union Tag tag; /* 0x00, w[3] at 0x0C */
    s32 f10;       /* 0x10 */
    s32 f14;       /* 0x14 */
    s32 f18;       /* 0x18 */
    s32 f1C;       /* 0x1C */
    u64 f20;       /* 0x20 */
    u64 f28;       /* 0x28 */
    u64 f30;       /* 0x30 */
    u64 f38;       /* 0x38 */
    u64 f40;       /* 0x40 */
    u64 f48;       /* 0x48 */
    u64 f50;       /* 0x50 */
    u64 f58;       /* 0x58 */
    u64 f60;       /* 0x60 */
    u64 f68;       /* 0x68 */
    u64 f70;       /* 0x70 */
    u64 f78;       /* 0x78 */
} Pkt;

void func_001414D0(Draw *d, union Rect *a, Range *r, union Rect *b,
                   s32 w, s32 h, s32 f) {
    s32 node;
    char *p;
    u64 bq;
    u64 aq;
    Buf *buf;
    Pkt *q;
    s32 x6;
    s32 y6;
    s32 ha;
    s32 hb;
    u64 packX;
    u64 packY;
    u64 packZ;
    u64 val30;
    u64 val40;

    node = d->link[d->count];
    p = node ? (char *)node + 8 : 0;
    if (p == 0) {
        return;
    }
    bq = b->q;
    aq = a->q;
    buf = (Buf *)(p + 0x28);
    x6 = (s32)((bq << 12) >> 26) << 6;
    y6 = (s32)((aq << 12) >> 26) << 6;
    q = (Pkt *)(buf->base + 16 * buf->count);
    if (x6 < 0x40) {
        x6 = 0x40;
    }
    if (y6 < 0x40) {
        y6 = 0x40;
    }
    if (r->fC - r->f4 <= 0) {
        return;
    }
    if (r->f8 - r->f0 <= 0) {
        return;
    }
    ha = y6 / 64;
    hb = x6 / 64;
    packX = ((u64)a->w[1] << 22) >> 26 << 24 | (u64)(s64)ha << 16 |
            (u64)(a->w[0] & 0x3FFF);
    packY = (u64)(s64)r->f0 << 16 | (u64)(s64)r->f4 | (u64)(s64)w |
            (u64)(s64)h << 16;
    packZ = (u64)(s64)(r->f8 - r->f0) | (u64)(s64)(r->fC - r->f4);
    q->tag.q = 0;
    q->tag.w[0] = 0x60000007;
    q->tag.w[3] = 0x50000007;
    q->f10 = 0x8006;
    q->f14 = 0x10000000;
    q->f18 = 0xE;
    q->f1C = 0;
    q->f20 = 0;
    q->f28 = 0x3F;
    val30 = packX | ((u64)b->w[1] << 22) >> 26 << 56 | (u64)(s64)hb << 16 |
            (u64)(b->w[0] & 0x3FFF);
    q->f30 = val30;
    q->f38 = 0x50;
    val40 = packY | (u64)(s64)f << 59;
    q->f40 = val40;
    q->f48 = 0x51;
    q->f50 = packZ;
    q->f58 = 0x52;
    q->f60 = 2;
    q->f68 = 0x53;
    q->f70 = 0;
    func_0014E130(p, 8, val40, val30);
    q->f78 = 0x3F;
    *(u128 *)d->cursor = D_003A0C40;
    *(u32 *)(d->cursor + 4) = (u32)((u64)q << 4);
    d->cursor = d->cursor + 0x10;
}
