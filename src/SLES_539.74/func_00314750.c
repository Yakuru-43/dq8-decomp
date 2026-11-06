// range: 0x314750 0x314840
#include "common.h"

struct Slot {
    u8 pad0[0xC];
    s16 sel;
    u8 pad1[0x5A];
    s32 cnt;
    u8 pad2[0x524];
};

struct Dest {
    u8 pad0[0x72];
    s16 val;
    u8 pad1[0xC];
};

s32 func_0035E590(struct Slot *);

extern struct Slot D_00421AD0 __attribute__((section(".data")));
extern struct Dest D_00452E60[4] __attribute__((section(".data")));

void func_00314750(void) {
    s32 count;
    s16 sel;
    struct Slot *p;
    s32 i;
    s32 j;
    s32 k;

    count = 0;
    sel = -1;
    p = &D_00421AD0;
    for (i = 0; i < 0x20; i++, p++) {
        if (func_0035E590(p) == 1) {
            if (0 < p->cnt) {
                sel = p->sel;
                count = count + 1;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        D_00452E60[j].val = -1;
    }
    if (count == 1) {
        for (k = 0; k < 4; k++) {
            D_00452E60[k].val = sel;
        }
    }
}
