// range: 0x45F580 0x45F630
// best: CLASS reorder+register score=6 — only kind (s1) / j (s0) swapped, all else byte-exact
#include "common.h"

struct ShopEntry {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 unk5;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 unk8;
};

int func_0045F630(s32, s32);

extern struct ShopEntry *D_003E0A24 __attribute__((section(".sdata")));
extern u16 D_003E1988 __attribute__((section(".sdata")));

s32 func_0045F580(void) {
    s32 total;
    struct ShopEntry *entry;
    s32 i;
    s16 kind;
    s32 j;

    total = 0;
    entry = D_003E0A24;
    for (i = 0; i < D_003E1988; i++, entry++) {
        if (0 < entry->unk6) {
            kind = entry->unk0;
            for (j = 1; j < entry->unk6 + 1; j++) {
                total += func_0045F630(kind, entry->unk5 + j);
            }
        }
    }
    return total;
}
