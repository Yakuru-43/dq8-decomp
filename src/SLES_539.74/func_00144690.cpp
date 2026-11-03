// range: 0x144690 0x144A70
// flags: -flag divbyzerocheck
// Pushes a copy of the current entry: the next slot of the pool of 8 gets
// the cursor's entry and becomes the cursor, while the pool is not full.
#include "common.h"

struct Vec4 {
    f32 x, y, z, w;
};

struct Entry {
    Entry() {}

    s32 f00, f04, f08, f0C; /* 0x000 */
    u8 f10;                 /* 0x010 */
    s32 f14[0xD];           /* 0x014 */
    u128 f50[6];            /* 0x050 */
    s32 fB0[0x10];          /* 0x0B0 */
    s32 fF0[0x10];          /* 0x0F0 */
    s32 f130[0x10];         /* 0x130 */
    Vec4 f170;              /* 0x170 */
    s32 f180[0x10];         /* 0x180 */
    s32 f1C0[0x10];         /* 0x1C0 */
    s32 f200[0x10];         /* 0x200 */
    Vec4 f240;              /* 0x240 */
    s32 f250[0x10];         /* 0x250 */
    s32 f290[0x10];         /* 0x290 */
    s32 f2D0[0x10];         /* 0x2D0 */
    s32 f310[0x18];         /* 0x310 */
    s32 f370[0x18];         /* 0x370 */
    s32 f3D0[0x10];         /* 0x3D0 */
    s32 f410[0x10];         /* 0x410 */
    s32 f450[0x10];         /* 0x450 */
    s32 f490[0x10];         /* 0x490 */
    Vec4 f4D0;              /* 0x4D0 */
    Vec4 f4E0;              /* 0x4E0 */
};

struct Pool {
    char unk0[0xF20];       /* 0x000 */
    Entry *cursor;          /* 0xF20 */
    char unkF24[0xC];       /* 0xF24 */
    Entry entries[8];       /* 0xF30 */
};

extern "C" void func_00144690(Pool *pool) {
    Entry *cur = pool->cursor;

    if (cur - pool->entries > 6) {
        return;
    }
    pool->cursor++;
    *pool->cursor = *cur;
}
