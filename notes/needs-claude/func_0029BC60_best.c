// range: 0x29BC60 0x29BDE0
// flags: -flag divbyzerocheck
// (the original guards both divides with bnez + break 0, 7: cf. func_002912C0.c)
#include "common.h"

typedef struct Unit0029BC60 {
    char pad[0x10];
    s16 slot;
} Unit0029BC60;

typedef struct Ai0029BC60 {
    char pad[0x490];
    s32 cursor[1];
} Ai0029BC60;

extern s32 func_00298380(Ai0029BC60 *ai, Unit0029BC60 *unit);
extern s32 func_00132D38(void);
extern u8 func_0029ACD0(Ai0029BC60 *ai, s32 index, Unit0029BC60 *unit, s32 arg);
extern void func_0029BB00(Ai0029BC60 *ai, Unit0029BC60 *unit);

void func_0029BC60(Ai0029BC60 *ai, Unit0029BC60 *unit, s32 arg)
{
    s32 idx;
    s32 j;
    s32 i;
    s32 flag;
    s32 mod;
    s32 *cursor;
    s32 budget;

    idx = func_00298380(ai, unit);
    if (idx >= 0) {
        cursor = &ai->cursor[idx];
        *cursor %= 2;
        for (i = 0; i < 2; i++) {
            switch (*cursor) {
            case 0:
                flag = 0;
                mod = 0;
                break;
            case 1:
                flag = 1;
                mod = 5;
                break;
            default:
                flag = 1;
                mod = 5;
                break;
            }
            mod = mod - flag;
            mod = func_00132D38();
            budget = mod + 1;
            mod = mod % budget;
            (*cursor)++;
            *cursor %= 2;
            for (j = 0; j < budget; j++) {
                if (func_0029ACD0(ai, flag + mod, unit, arg) == 1) {
                    return;
                }
                mod = (mod + 1) % budget;
            }
        }
    }
    func_0029BB00(ai, unit);
}
