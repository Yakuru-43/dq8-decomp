// range: 0x29C950 0x29CAF0
#include "common.h"

union Hw0029C950 {
    u16 h;
    u8 b[2];
};

struct Entry0029C950 {
    char pad0[0x10];
    union Hw0029C950 f10;
    union Hw0029C950 f12;
    char pad14[0x590 - 0x14];
};

extern struct Entry0029C950 *func_002975E0(void *arg0, u32 arg1);
extern s32 func_00201760(struct Entry0029C950 *entry, s32 arg1);
extern s32 func_0035E570(struct Entry0029C950 *entry);
extern s32 func_0012D4C0(s32 arg0);
extern void func_00300CB0(s32 arg0, void *arg1, s32 arg2);
extern char D_00421AD0 __attribute__((section(".data")));
extern char D_003CBEA0 __attribute__((section(".data")));

struct Entry0029C950 *func_0029C950(void *arg0, u32 kind, u32 sel, s32 mode)
{
    struct Entry0029C950 *list;
    struct Entry0029C950 *entry;
    struct Entry0029C950 *best;
    s32 key;
    s32 i;
    s32 bestScore;
    s32 score;

    key = ((kind & 0xFF) << 8) | (sel & 0xFF);
    best = 0;
    list = func_002975E0(&D_00421AD0, kind);
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
    func_00300CB0(0 < best, &D_003CBEA0, 0xCCD);
    return best;
}
