// range: 0x29BB90 0x29BC60
#include "common.h"

typedef struct Unit0029BB90 {
    char pad[0x10];
    s16 slot;
} Unit0029BB90;

typedef struct Ai0029BB90 {
    char pad[0x510];
    s32 cursor[1];
} Ai0029BB90;

extern u8 func_0029ACD0(Ai0029BB90 *ai, s32 index, Unit0029BB90 *unit, s32 arg);
extern void func_0029BB00(Ai0029BB90 *ai, Unit0029BB90 *unit);

void func_0029BB90(Ai0029BB90 *ai, Unit0029BB90 *unit, s32 arg)
{
    s32 i;
    s32 *cursor;

    cursor = &ai->cursor[unit->slot];
    *cursor %= 6;
    for (i = 0; i < 6; i++) {
        s32 index = *cursor;
        *cursor = index + 1;
        *cursor %= 6;
        if (func_0029ACD0(ai, index, unit, arg) == 1) {
            return;
        }
    }
    func_0029BB00(ai, unit);
}
