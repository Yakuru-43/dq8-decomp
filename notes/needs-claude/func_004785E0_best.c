// range: 0x4785E0 0x4786E0
// best attempt; CLASS structural score=57 — register allocation wrong, see
// notes/needs-claude/func_004785E0.md
#include "common.h"

typedef struct { /* 0x4C */
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 count;
    /* 0x08 */ s32 field_08;
    /* 0x0C */ char *names[16];
} MenuEntry4C;

extern s32 D_003E1B3C __attribute__((section(".sdata")));
extern s32 D_003E1B40 __attribute__((section(".sdata")));
extern s32 D_003E1B44 __attribute__((section(".sdata")));

s32 func_001667C0(char *);                                          /* extern */
char *func_00166760(char *);                                        /* extern */
s32 func_001341D8(char *);                                          /* extern */
char *func_0014EA80(s32, s32);                                      /* extern */
char *func_001340C0(char *, char *);                                /* extern */

s32 func_004785E0(char *arg0, s32 arg1) {
    MenuEntry4C *entry;
    s32 count;
    s32 i;
    char *cursor;
    char *name;
    char **slot;
    s32 idx;

    count = arg1;
    cursor = arg0 + 8;
    idx = D_003E1B44;
    entry = (MenuEntry4C *)(*(s32 *)(D_003E1B3C + 0x168) + idx * 76);
    D_003E1B44 = idx + 1;
    entry->field_00 = func_001667C0(arg0);
    entry->count = count - 2;
    entry->field_08 = func_001667C0(cursor);
    cursor += 8;
    for (i = 0; i < entry->count && i < 16; i++) {
        name = func_00166760(cursor);
        cursor += 8;
        slot = &entry->names[i];
        *slot = func_0014EA80(func_001341D8(name) + 1, D_003E1B40);
        func_001340C0(*slot, name);
    }
    return 1;
}
