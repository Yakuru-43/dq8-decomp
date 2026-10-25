// range: 0x4601B0 0x460290
// rodata: 0x483F70 0x483F88
#include "common.h"

typedef struct {
    s16 unk0;
    char pad2[0x6];
    s16 unk8;
    s16 unkA;
    char padC[0x2];
    s16 unkE;
    s32 unk10;
    s32 unk14;
} Unk485120;

extern Unk485120 D_00485120[16] __attribute__((section(".data")));

void func_004601B0(void) {
    Unk485120 *p = D_00485120;
    s32 i;

    for (i = 0; i < 16; i++, p++) {
        if (p->unk0 < 0) {
            continue;
        }
        if (0 < p->unkE) {
            p->unkE--;
            continue;
        }
        switch (p->unk8) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            if (p->unk14 > 0) {
                p->unk10++;
                if (p->unk10 >= p->unk14) {
                    if (p->unkA == -1) {
                        p->unk10 = 0;
                    } else if (p->unkA == -2) {
                        p->unk10 = p->unk14;
                    } else if (p->unkA <= 0) {
                        p->unk14 = 0;
                        p->unk0 = -1;
                    } else {
                        p->unkA--;
                        p->unk10 = 0;
                    }
                }
            }
            break;
        }
    }
}
