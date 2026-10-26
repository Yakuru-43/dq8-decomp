// range: 0x311800 0x311910
#include "common.h"

struct Owner {
    char pad0[0x62];
    s16 field62;
    char pad64[4];
    s32 slots[6];
};

extern s32 func_0015F450(void);
s32 func_00161CA0(s32, char *, s32 *, s32, s32 *, s32); /* extern */
s32 func_002252E0(struct Owner *, s32);                  /* extern */
s32 func_00130FD0(s32, s32, s32);                        /* extern */
void func_0015A4A0(s32, s32, s32, s32, s32);             /* extern */
extern char D_003D09F0[];

void func_00311800(struct Owner *o, s32 ident) {
    s32 mgr;
    s32 count;
    s32 i;
    s32 alloc;
    s32 ptrs[8];
    s32 sizes[8];

    mgr = func_0015F450();
    for (i = 0; i < 6; i++) {
        o->slots[i] = 0;
    }
    count = func_00161CA0(ident, D_003D09F0, ptrs, 8, sizes, 0);
    for (i = 0; i < count; i++) {
        alloc = func_002252E0(o, (sizes[i] >> 4) + 1);
        func_00130FD0(alloc, ptrs[i], sizes[i]);
        func_0015A4A0(mgr, alloc, o->field62, 0, 0);
        o->slots[i] = alloc;
    }
}
