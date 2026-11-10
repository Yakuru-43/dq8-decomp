// range: 0x460EE0 0x460F80
// Best attempt — everything matches except r's register colour (see the .md).
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ u8 _4[8];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ u8 _E[0x582];
} BattleEntry;

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u32 unkC;
} BattleRec;

M2C_UNK func_00460F80();                              /* extern */
M2C_UNK func_00460FF0();                              /* extern */

void func_00460EE0(void *arg0, BattleEntry *entries, s32 count) {
    s32 i;
    BattleRec *r;

    if (arg0 == 0) {
        return;
    }
    for (i = 0; i < count; i++, entries++) {
        func_00460F80();
        r = (BattleRec *)func_00460FF0(entries->unk0);
        if (r != 0) {
            r->unk8 = entries->unkC;
            r->unkA = entries->unk0;
            r->unk4 = 0;
            r->unk0 = 1;
            r->unkC = (u32)r;
        }
    }
}
