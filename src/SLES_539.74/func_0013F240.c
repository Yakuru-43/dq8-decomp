// range: 0x13F240 0x13F300
#include "common.h"

typedef struct GSWriter {
    char pad0[0x70];          /* 0x00 */
    union {
        struct {
            u8 type : 3;
            u8 rest : 5;
        } b;
        s64 prim;
    } prim;                   /* 0x70 */
    char pad78[0xF4 - 0x78];  /* 0x78 */
    char *wp;                 /* 0xF4 */
    char *f8;                 /* 0xF8 */
    char *fc;                 /* 0xFC */
    s32 *p100;                /* 0x100 */
    s32 *p104;                /* 0x104 */
    s32 *p108;                /* 0x108 */
    s32 unk10C;               /* 0x10C */
    f32 unk110;               /* 0x110 */
    s32 unk114;               /* 0x114 */
    s32 nreg;                 /* 0x118 */
} GSWriter;

void func_0013F240(GSWriter *w, s32 type, s32 a2, s32 a3, s32 nreg) {
    s32 *p;
    s64 bits;
    s32 word;

    w->unk114 = 1;
    w->prim.b.type = type;
    w->unk110 = 1.0f;
    w->f8 = w->wp;
    w->fc = w->f8;
    p = (s32 *)w->wp;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    w->p104 = p;
    w->p108 = p + 3;
    w->wp = w->wp + 0x10;
    bits = w->prim.prim;
    w->nreg = nreg;
    word = (s32)(bits & 0x7FF) << 15;
    p = (s32 *)w->wp;
    w->p100 = p;
    p[0] = 0x8000;
    p[1] = (w->nreg << 28) | word | 0x4000;
    p[2] = a2;
    p[3] = a3;
    w->wp = w->wp + 0x10;
}
