// range: 0x29C950 0x29CAF0
#include "common.h"

union KindSel0029C950 {
    s16 h;
    u8 b[2];
};

struct Entry0029C950 {
    char pad0[0x10];
    union KindSel0029C950 f10;
    union KindSel0029C950 f12;
    char pad14[0x590 - 0x14];
};

extern s32 func_002975E0(s32 arg0);
extern s32 func_00201760(void *arg0, s32 *arg1);
extern s32 func_0035E570(void *arg0);
extern s32 func_0012D4C0(s32 arg0);
M2C_UNK func_00300CB0(M2C_UNK, M2C_UNK *, M2C_UNK); /* extern */
extern char D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_003CBEA0 __attribute__((section(".data")));

/* pick the table entry whose (kind, sel) pair scores nearest,
 * skipping the free slots (f10 0/1) on the side kind selects */
struct Entry0029C950 *func_0029C950(void *owner, u32 kind, u32 sel, s32 mode)
{
    struct Entry0029C950 *list;
    struct Entry0029C950 *entry;
    struct Entry0029C950 *best;
    u32 key;
    s32 i;
    s32 bestScore;
    s32 score;

    key = ((kind & 0xFF) << 8) | (sel & 0xFF);
    best = 0;
    list = (struct Entry0029C950 *)func_002975E0((s32)&D_00421AD0);
    bestScore = -1;
    for (i = 0; i < 32; i++) {
        entry = &list[i];
        if (kind < 2) {
            if (entry->f10.h != 0 && entry->f10.h != 1) {
                continue;
            }
        } else {
            if (entry->f10.h == 0 || entry->f10.h == 1) {
                continue;
            }
        }
        if (func_00201760(entry, 0) <= 0) {
            continue;
        }
        if (func_0035E570(entry) != 0) {
            continue;
        }
        if (mode != 0) {
            if (entry->f10.h == kind) {
                if (entry->f12.h == sel) {
                    continue;
                }
            }
        }
        score = func_0012D4C0(key - ((entry->f10.b[0] << 8) | entry->f12.b[0]));
        if (score < bestScore || bestScore < 0) {
            best = entry;
            bestScore = score;
        }
    }
    func_00300CB0(0 < (u32)best, &D_003CBEA0, 0xCCD);
    return best;
}
