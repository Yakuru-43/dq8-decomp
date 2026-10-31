// Best attempt for func_0014EA80 (score 38 structural). Range 0x14EA80 0x14EB30.
// See notes/needs-claude/func_0014E9D0.md: the asm is byte-identical to this
// function's body (same instructions, same registers, same block layout).
#include "common.h"

M2C_UNK DebugPrintf(M2C_UNK *); /* extern */
extern M2C_UNK D_003C2040;

typedef struct {
    s32 fields_00[8];
    s32 locked;  /* 0x20 */
    s32 field_24;
    u32 base;    /* 0x28 */
    s32 count;   /* 0x2C */
    s32 field_30;
    s32 max;     /* 0x34 */
} Arena;

extern "C" {

s32 func_0014EA80(u32 size, Arena *arena) {
    s32 units;
    u32 base;
    s32 old;
    bool hasBase;

    if (size & 0xF) {
        units = (s32)(size >> 4) + 1;
    } else {
        units = (s32)(size >> 4);
    }
    base = arena->base;
    hasBase = (0 < base);
    if (hasBase == false) {
        return 0;
    }
    if (arena->locked != 0) {
        return 0;
    }
    if (units <= 0) {
        return 0;
    }
    if (arena->max < arena->count + units) {
        DebugPrintf(&D_003C2040);
        return 0;
    }
    old = arena->count;
    arena->count = arena->count + units;
    return base + (old << 4);
}

}
