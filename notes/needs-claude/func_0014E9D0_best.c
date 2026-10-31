// Best C for func_0014E9D0 (did not match: CLASS structural score=38, 140 vs 164 B).
// See notes/needs-claude/func_0014E9D0.md for the diff analysis.
// range: 0x14E9D0 0x14EA80
#include "common.h"

void DebugPrintf(s32 *fmt);
extern s32 D_003C2040 __attribute__((section(".data")));

typedef struct {
    s32 fields_00[8];
    /* 0x20 */ s32 locked;
    s32 field_24;
    /* 0x28 */ u32 base;
    /* 0x2C */ s32 count;
    s32 field_30;
    /* 0x34 */ s32 max;
} Arena;

static inline s32 HasBase(u32 base) {
    return base > 0;
}

s32 func_0014E9D0(u32 size, Arena *arena) {
    s32 units;
    u32 base;
    s32 cur;

    if (size & 0xF) {
        units = (s32)(size >> 4) + 1;
    } else {
        units = (s32)(size >> 4);
    }
    base = arena->base;
    if (HasBase(base)) { /* plain `base > 0` folds to beql $a2; orig has sltu v0 */
        if (arena->locked == 0) {
            if (units <= 0) {
                return 0;
            }
            cur = arena->count;
            if (arena->max < cur + units) {
                DebugPrintf(&D_003C2040);
                return 0;
            }
            arena->count = arena->count + units;
            return base + (cur << 4);
        }
        return 0;
    }
    return 0;
}
