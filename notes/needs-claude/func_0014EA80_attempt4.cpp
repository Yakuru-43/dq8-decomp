// range: 0x14EA80 0x14EB30
#include "common.h"

extern "C" {

void DebugPrintf(char *, s32, s32, void *);
extern char D_003C2040[];

typedef struct Stack {
    char pad_00[0x20];
    s32 flag20;  /* 0x20 */
    char pad_24[4];
    u32 base28;  /* 0x28 */
    s32 count2C; /* 0x2C */
    s32 field_30;
    s32 limit34; /* 0x34 */
    s32 pcount() const { return count2C; }
    void pbump(s32 n) { count2C += n; }
} Stack;

static inline s32 HasSpace(u32 base) { return 0 < base; }

s32 func_0014EA80(u32 size, Stack *stack) {
    s32 units;
    s32 result;
    u32 base;
    s32 cur;

    if (size & 0xF) {
        units = (s32)(size >> 4) + 1;
    } else {
        units = (s32)(size >> 4);
    }
    base = stack->base28;
    if (HasSpace(base) == 0) {
        return 0;
    }
    if (stack->flag20 != 0) {
        goto unlocked2;
    }
    goto unlocked;
unlocked2:
    result = 0;
    goto done;
unlocked:
    if (units <= 0) {
        result = 0;
        goto done;
    }
    cur = stack->pcount();
    if (stack->limit34 < cur + units) {
        DebugPrintf(D_003C2040, cur + units, stack->limit34, stack);
        result = 0;
    } else {
        cur = stack->pcount();
        result = base + (cur << 4);
        stack->count2C = cur + units;
    }
done:
    return result;
}

}
