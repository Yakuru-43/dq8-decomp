// range: 0x313E00 0x313F30
#include "common.h"

struct Entry {
    u8 pad0[0x100];
    s8 list[0x1A];
    s8 active;
    u8 pad11B[0x81];
};

extern void func_001FA870(s32, s8 *);
extern void func_00313F30(struct Entry *, char *);
extern void func_00314360(struct Entry *);

extern struct Entry *D_003E11A0 __attribute__((section(".sdata")));
extern s16 D_003E11A4 __attribute__((section(".sdata")));
extern char D_00452DE0[] __attribute__((section(".data")));

s32 func_00313E00(s32 arg0, s32 arg1) {
    struct Entry *e;
    s32 i;
    s32 j;
    s32 best;
    s32 count;
    s8 v;

    for (i = 0, e = D_003E11A0; i < D_003E11A4; i++, e++) {
        if (e->active == 0) {
            continue;
        }
        best = -1;
        count = 0;
        for (j = 0; j < 0x1A; j++) {
            v = e->list[j];
            if (0 <= v) {
                count++;
            }
            if (v == arg0) {
                if (best < 0) {
                    best = j;
                }
            }
        }
        if (best < 0) {
            continue;
        }
        e->list[best] = -1;
        for (; best < 0x19; best++) {
            e->list[best] = e->list[best + 1];
        }
        if (count - 1 > 0) {
            continue;
        }
        func_001FA870(arg1, &e->active);
        func_00313F30(e, D_00452DE0);
        func_00314360(e);
    }
    return 0;
}
