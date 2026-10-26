// range: 0x29BF00 0x29BFE0
#include "common.h"

typedef struct Unit0029BF00 {
    char pad[0x10];
    s16 slot;
} Unit0029BF00;

typedef struct Ai0029BF00 {
    char pad[0x490];
    s32 cursor[1];
} Ai0029BF00;

extern s32 func_00298380(Ai0029BF00 *ai, Unit0029BF00 *unit);
extern u8 func_0029ACD0(Ai0029BF00 *ai, s32 index, Unit0029BF00 *unit, s32 arg);
extern void func_0029BB00(Ai0029BF00 *ai, Unit0029BF00 *unit);

void func_0029BF00(Ai0029BF00 *ai, Unit0029BF00 *unit, s32 arg)
{
    s32 i;
    s32 *cursor;
    s32 idx;

    idx = func_00298380(ai, unit);
    if (idx >= 0) {
        cursor = &ai->cursor[idx];
        *cursor %= 6;
        for (i = 0; i < 6; i++) {
            s32 index = *cursor;
            *cursor = index + 1;
            *cursor %= 6;
            if (func_0029ACD0(ai, index, unit, arg) == 1) {
                return;
            }
        }
    }
    func_0029BB00(ai, unit);
}
