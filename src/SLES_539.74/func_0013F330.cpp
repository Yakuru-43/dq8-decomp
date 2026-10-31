// range: 0x13F330 0x13F450
// GS packet writer begin: points the writer at the object's buffer end and
// writes the DMA/GIF headers. With no object it returns without a value
// (the original leaves $v0 untouched there).
#include "common.h"

extern "C" {

s32 func_00157BC0(void *, char *);                 /* extern */

struct GSObj {
    char unk0[0x28];         /* 0x00 */
    char *buf;               /* 0x28 */
    s32 qwc;                 /* 0x2C */
};

struct GSWriter {
    void SetBase(char *buf) {
        base = buf;
        if (f0 == 0) {
            f0 = (char *)((u32)base & 0x0FFFFFFF);
        }
    }
    char *Base() const { return base; }

    GSObj *obj;              /* 0x00 */
    char unk4[0x10 - 0x04];  /* 0x04 */
    char regs[0xE8 - 0x10];  /* 0x10 */
    s32 flag;                /* 0xE8 */
    char *base;              /* 0xEC */
    char *f0;                /* 0xF0 */
    char *wp;                /* 0xF4 */
    char *f8;                /* 0xF8 */
    char *fc;                /* 0xFC */
    s32 *p100;               /* 0x100 */
};

s32 func_0013F330(GSWriter *w) {
    s32 *p;
    s64 *q;
    s32 n;

    w->flag = 1;
    if (w->obj == 0) {
        return n;
    }
    w->flag = 0;
    w->base = w->obj->buf + (w->obj->qwc << 4);
    w->SetBase(w->Base());
    w->wp = w->base;
    p = (s32 *)w->wp;
    p[0] = 0x10000009;
    p[2] = 0;
    p[1] = 0;
    p[3] = 0x50000009;
    w->wp = w->wp + 0x10;
    p = (s32 *)w->wp;
    w->p100 = p;
    p[0] = 0x8002;
    p[1] = 0x10000000;
    p[2] = 0xE;
    p[3] = 0;
    w->wp = w->wp + 0x10;
    q = (s64 *)w->wp;
    q[0] = 0;
    q[1] = 0x3F;
    q[2] = 1;
    q[3] = 0x1A;
    w->wp = (char *)(q + 4);
    n = func_00157BC0(w->regs, w->wp);
    w->wp = w->wp + (n << 4);
    return n;
}

}
