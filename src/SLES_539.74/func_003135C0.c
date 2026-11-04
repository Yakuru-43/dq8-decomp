// range: 0x3135C0 0x313810
#include "common.h"

struct Reader {
    char pad0[0x4];  /* +0x00 */
    s32 active;      /* +0x04 */
    char pad8[0x14]; /* +0x08 */
    char src[4];     /* +0x1C */
    char pad20[0x1C]; /* +0x20 */
    s32 tag1;        /* +0x3C */
    char pad40[0x1C]; /* +0x40 */
    s32 tag2;        /* +0x5C */
    char pad60[0xC]; /* +0x60 */
    s32 tag3;        /* +0x6C */
    char pad70[0x3C]; /* +0x70 */
    s32 idxAC;       /* +0xAC */
    s32 outB0;       /* +0xB0 */
    char padB4[0x8]; /* +0xB4 */
    s32 idxBC;       /* +0xBC */
    s32 idxC0;       /* +0xC0 */
    char padC4[0x8]; /* +0xC4 */
    s32 outCC;       /* +0xCC */
    char padD0[0x4]; /* +0xD0 */
    s32 outD4;       /* +0xD4 */
};

extern char D_003D0A40[];
extern char D_003D0A50[];
extern char D_003D0A60[];
extern char D_003D0A70[];

extern void func_001339E0(void *, char *, void *, void *);
extern s32 func_0018FCE0(void *);
extern void func_0014E130(void *, s32);
extern void func_0014E030(void *);
extern s32 func_001632D0(void *, s32, s32 *);
extern s32 func_001629F0(void *, s32, s32 *);
extern void func_00162BC0(void);
extern void func_001632E0(void);
extern s32 func_00313870(void *, s32, s32 *, s32);

s32 func_003135C0(struct Reader *r, void *arg1, s32 arg2) {
    s32 out15C;
    s32 out158;
    char buf1[0x40];
    char buf2[0x40];
    char buf3[0x40];
    char buf4[0x40];
    s32 found;

    func_001339E0(buf1, D_003D0A40, r->src, &r->tag1);
    func_001339E0(buf2, D_003D0A50, r->src, &r->tag2);
    func_001339E0(buf3, D_003D0A60, r->src, &r->tag3);
    func_001339E0(buf4, D_003D0A70, r->src, &r->tag1);
    r->active = 1;
    r->outCC = 0;
    r->outD4 = 0;
    out15C = 0;
    if (arg2 != 0) {
        func_00162BC0();
        func_001632E0();
    }
    found = 0;
    if (arg2 != 0) {
        r->outCC = func_0018FCE0(arg1);
        if (func_001632D0(buf4, r->outCC, &out15C) != 0) {
            found = 1;
        }
    } else {
        r->outCC = func_0018FCE0(arg1);
        if (func_001629F0(buf4, r->outCC, &out15C) != 0) {
            found = 1;
        }
    }
    if (out15C != 0) {
        func_0014E130(arg1, (out15C >> 4) + 1);
    }
    if (found == 0) {
        r->outCC = 0;
        r->active = 0;
    }
    if (r->active == 0) {
        r->idxAC = func_0018FCE0(arg1);
        if (func_00313870(buf1, r->idxAC, &r->outB0, arg2) == 0) {
            return 0;
        }
        func_0014E130(arg1, (r->outB0 >> 4) + 1);
        func_0014E030(arg1);
        r->idxBC = func_0018FCE0(arg1);
        if (func_00313870(buf2, r->idxBC, &out158, arg2) == 0) {
            return 0;
        }
        func_0014E130(arg1, (out158 >> 4) + 1);
        func_0014E030(arg1);
        r->idxC0 = func_0018FCE0(arg1);
        if (func_00313870(buf3, r->idxC0, &r->outD4, arg2) == 0) {
            return 0;
        }
        func_0014E130(arg1, (r->outD4 >> 4) + 1);
    }
    func_0014E030(arg1);
    return 1;
}
