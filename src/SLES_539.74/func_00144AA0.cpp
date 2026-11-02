// range: 0x144AA0 0x144C60
// flags: -flag divbyzerocheck
// Pushes a copy of the current entry: the next slot gets the cursor's entry
// and becomes the cursor, as long as the pool of 8 is not full.
#include "common.h"

struct Vec2 {
    f32 x, y;
};

struct Pair64 {
    s64 a, b;
};

struct Vec4 {
    f32 x, y, z, w;
};

struct Entry {
    Entry() {}

    s32 f00, f04, f08, f0C, f10, f14, f18, f1C; /* 0x000 */
    s32 f20, f24, f28, f2C, f30, f34, f38;      /* 0x020 */
    Vec2 f3C;     /* 0x03C */
    s32 f44[10];  /* 0x044 */
    Pair64 f70;   /* 0x070 */
    s64 f80[16];  /* 0x080 */
    s64 f100[12]; /* 0x100 */
    Vec4 f160;    /* 0x160 */
    s32 f170, f174, f178, f17C, f180, f184; /* 0x170 */
    s32 f188;     /* 0x188 */
};

struct Pool {
    char unk0[0x270];  /* 0x000 */
    Entry *cursor;     /* 0x270 */
    char unk274[0xC];  /* 0x274 */
    Entry entries[8];  /* 0x280 */
};

extern "C" void func_00144AA0(Pool *pool) {
    Entry *cur = pool->cursor;

    if (cur - pool->entries > 6) {
        return;
    }
    pool->cursor++;
    *pool->cursor = *cur;
}
