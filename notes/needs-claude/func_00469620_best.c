// range: 0x469620 0x469780
// best attempt: 344/344 bytes, CLASS structural score=63 (2026-11-04, Qwen factory-6)
#include "common.h"

typedef struct {
    s32 pad_00[8];
    s32 value;
    s32 pad_24[7];
} Slot; /* 0x40 */

extern Slot *D_003E17B0;
extern s32 D_003E17A8;

void func_00469620(s32 arg0) {
    Slot *tbl;
    Slot *slot;
    s32 used[16];
    s32 n;
    u8 ok;
    s32 j;
    s32 k;
    s32 count;
    s32 cand;
    u8 free;
    s32 m;
    s32 val;

    tbl = D_003E17B0;
    n = 0;
    ok = 1;
    j = 10;
    slot = tbl + arg0;
    do {
        if (j != arg0) {
            val = tbl[j].value;
            used[n] = val;
            n = n + 1;
            if (val == slot->value) {
                ok = 0;
            }
        }
        j = j + 1;
    } while (j < 16);
    count = D_003E17A8;
    tbl = D_003E17B0;
    for (k = 0; k < count; k++) {
        val = tbl[k].value;
        used[n] = val;
        n = n + 1;
        if (val == slot->value) {
            ok = 0;
        }
        if (tbl[(k + 1) % 10].value == slot->value) {
            ok = 0;
        }
    }
    if (ok) {
        return;
    }
    cand = 1;
    free = 1;
    while (cand < 25 && free) {
        ok = 1;
        for (m = 0; m < n; m++) {
            if (used[m] == cand) {
                ok = 0;
            }
        }
        if (ok) {
            free = 0;
            D_003E17B0[arg0].value = cand;
        }
        cand = cand + 1;
    }
}
