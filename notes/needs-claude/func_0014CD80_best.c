// range: 0x14CD80 0x14CE20
// best attempt: factory-1 2026-11-05, CLASS structural score=10 (10 words
// differ), 160 vs 160 bytes. The prior session's best (explicit else,
// `count = 0; base = 0;` variant) is in notes/.scratch_w1/. See
// notes/needs-claude/func_0014CD80.md for the layout analysis.
#include "common.h"

typedef struct {
    u8 pad_0[0xC];
    s32 count;
    u8 pad_10[4];
    s32 stride;
    char *table;
} Struct14CD80;

s32 func_0014CE20(char *arg0, char *arg1);

char *func_0014CD80(char **arg0, char *arg1) {
    Struct14CD80 *desc;
    char *base;
    s32 i;
    s32 count = 0;

    desc = (Struct14CD80 *)(*arg0);
    if (desc == NULL) {
        return 0;
    }
    if (desc != NULL) {
        base = desc->table;
        count = desc->count;
    }
    i = 0;
    while (i < count) {
        if (func_0014CE20(arg1, *(char **)base) != 0) {
            return base;
        }
        i++;
        base += ((Struct14CD80 *)(*arg0))->stride;
    }
    return 0;
}
