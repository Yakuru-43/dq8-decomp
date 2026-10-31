// Best .cpp attempt for func_0014E9D0 (did not match: CLASS structural score=39,
// 144 vs 164 B). bool != false guard + nested positive ifs + shared trailing return 0.
// See notes/needs-claude/func_0014E9D0.md for the diff analysis.
// range: 0x14E9D0 0x14EA80
#include "common.h"

extern "C" {

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

s32 func_0014E9D0(u32 size, Arena *arena) {
    s32 units;
    u32 base;
    s32 cur;
    bool has_base;

    if (size & 0xF) {
        units = (s32)(size >> 4) + 1;
    } else {
        units = (s32)(size >> 4);
    }
    base = arena->base;
    has_base = base > 0;
    if (has_base != false) {
        if (arena->locked == 0) {
            if (units > 0) {
                cur = arena->count;
                if (arena->max >= cur + units) {
                    arena->count = arena->count + units;
                    return base + (cur << 4);
                }
                DebugPrintf(&D_003C2040);
            }
        }
        return 0;
    }
    return 0;
}

}
