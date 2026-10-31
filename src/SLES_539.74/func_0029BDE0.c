// range: 0x29BDE0 0x29BF00
#include "common.h"

typedef struct Unit0029BDE0 {
    char pad[0x10];
    s16 slot;
} Unit0029BDE0;

typedef struct Ai0029BDE0 {
    char pad[0x490];
    s32 cursor[1];
} Ai0029BDE0;

extern s32 func_00298380(Ai0029BDE0 *ai, Unit0029BDE0 *unit);
extern s32 func_00132D38(void);
extern u8 func_0029ACD0(Ai0029BDE0 *ai, s32 index, Unit0029BDE0 *unit, s32 arg);
extern void func_0029BB00(Ai0029BDE0 *ai, Unit0029BDE0 *unit);

void func_0029BDE0(Ai0029BDE0 *ai, Unit0029BDE0 *unit, s32 arg)
{
    s32 i;
    s32 other;
    s32 *cursor;
    s32 idx;

    idx = func_00298380(ai, unit);
    if (idx >= 0) {
        cursor = &ai->cursor[idx];
        *cursor %= 3;
        for (i = 0; i < 3; i++) {
            s32 r = func_00132D38();
            s32 index = *cursor;
            s32 bit = r & 1;
            other = (index << 1) + (bit ^ 1);
            *cursor = index + 1;
            *cursor %= 3;
            if (func_0029ACD0(ai, (index << 1) + bit, unit, arg) == 1) {
                return;
            }
            if (func_0029ACD0(ai, other, unit, arg) == 1) {
                return;
            }
        }
    }
    func_0029BB00(ai, unit);
}
