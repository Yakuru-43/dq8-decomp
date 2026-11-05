// Parked best C for func_00174400 (needs-claude, 2026-11-05 factory-1).
// try_match: CLASS structural score=16; word-exact 0x00..0xBF; see
// notes/needs-claude/func_00174400.md for the diff and what was tried.
// range: 0x174400 0x174500
#include "common.h"

extern "C" {

extern char D_004055F0[];

struct Category { /* 56 bytes */
    char unk0[0x18];
    s32 count;    /* 0x18 */
    char *items;  /* 0x1C */
};

struct Lookup {
    void Set00(char *p) { f0 = p; }
    char *Get00() const { return f0; }
    void Set04(char *p) { f4 = p; }
    char *Get04() const { return f4; }
    void Set08(char *p) { f8 = p; }
    char *Get08() const { return f8; }

    char *f0;  /* 0x00 */
    char *f4;  /* 0x04 */
    char *f8;  /* 0x08 */
    s32 fC;    /* 0x0C */
};

void func_00174400(Lookup *w, u32 packed, s32 index) {
    s32 type;
    s32 cat;
    char *base;
    char *p;
    Category *c;

    type = (packed >> 24) & 0xFF;
    cat = (packed >> 16) & 0xFF;
    w->f4 = 0;
    w->f8 = 0;
    w->fC = -1;
    if (type >= 0 && type < 17) {
        base = &D_004055F0[type * 480];
    } else {
        base = 0;
    }
    w->Set00(base);
    p = w->Get00();
    if (p == 0) {
        return;
    }
    if (cat >= 0 && cat < 5) {
        base = p + cat * 56 + 0x18;
    } else {
        base = 0;
    }
    w->Set04(base);
    c = (Category *)w->Get04();
    if (c == 0) {
        return;
    }
    if (index >= 0 && index < c->count) {
        base = c->items + index * 12;
    } else {
        base = 0;
    }
    w->Set08(base);
    if (w->Get08() != 0) {
        w->fC = index;
    }
}

}
