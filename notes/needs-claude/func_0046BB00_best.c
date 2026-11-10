// range: 0x46BB00 0x46BC20
// NOT MATCHED (needs-claude): best draft, CLASS structural score=53.
// CW rematerializes (r + 0x118) into the load instead of keeping the entry
// pointer in $s1 like the original; see func_0046BB00.md.
#include "common.h"

typedef struct BattleList {
    /* 0x00 */ u8 pad0[0x114];
    /* 0x114 */ s32 count;
    /* 0x118 */ s32 items[1];
} BattleList;

char *func_359CF0(M2C_UNK *, s32);
char *func_16D5B0(s32, s32);
void func_357E30(char *, void *);
void func_151AB0(void *, void *);
char *func_2CD100(s32, s32, s32);
void func_2C9E50(s32, s32, f32);
void func_286B30(char *, char *);
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern char D_00484110[];
extern char D_00484120[];
extern char D_00484128[];
extern char D_00484130[];

void func_0046BB00(BattleList *list, s32 arg1) {
    s32 i;
    s32 sp60[4];
    char *entry;
    char *r;
    char *entry3;
    char *r2;
    char *r3;

    for (i = 0; i < list->count; i++) {
        r = func_359CF0(&D_421AD0, list->items[i]);
        entry = r + 0x118;
        if (r != 0) {
            r2 = func_16D5B0(arg1, *(s32 *)entry);
            if (r2 != 0) {
                func_357E30(r, sp60);
                func_151AB0(r2, sp60);
                r3 = func_2CD100(arg1, list->items[i], 4);
                entry3 = r3 + 0x118;
                func_2C9E50(arg1, *(s32 *)entry3, 1.0f);
                func_286B30(r2, D_00484110);
                func_286B30(r2, D_00484120);
                func_286B30(r2, D_00484128);
                func_286B30(r2, D_00484130);
            }
        }
    }
    list->count = 0;
}
