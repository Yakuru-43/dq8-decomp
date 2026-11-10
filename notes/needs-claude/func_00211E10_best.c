// best draft for func_00211E10 (NOT matched, NOT to be built) — see
// notes/needs-claude/func_00211E10.md for the CLASS line and the walls.
// range: 0x211E10 0x211FF0
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s8 unk4;
    char pad5[0x1F];
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s8 unk3C;
    char pad3D[3];
    char pad40[0x28];
    /* 0x68 */ char unk68[0x20];
    /* 0x88 */ s32 unk88;
    /* 0x8C */ s32 unk8C;
    char pad90[0x10];
} MsgSlot;

extern MsgSlot *D_003E0928;
extern MsgSlot *D_003E0950;
extern s16 D_003E092C;
extern f32 D_003A58E4;
extern f32 D_003A58EC;
extern char D_00415C80[];

char *func_00166760(char *);
s32 func_001667C0(char *);
f32 func_00166780(char *);
void func_001340C0(void *, char *);
void func_0013C680(f32 *, char *, f32 *);   /* asm function */
s32 func_0015F450(f32 *);
s32 func_0015AEF0(s32, void *, s32);

s32 func_00211E10(char *arg0) {
    char *id;
    char *cursor;
    MsgSlot *slot;
    s32 i;
    s32 r;
    s32 handle;
    f32 va;
    f32 vb;
    f32 vc;
    f32 buf[4];
    MsgSlot *table;

    table = D_003E0928;
    cursor = arg0;
    D_003E0950 = NULL;
    for (i = 0; i < 32; i++) {
        D_003E0950 = &table[i];
        if (table[i].unk4 == 0) {
            break;
        }
    }
    slot = D_003E0950;
    if (slot == NULL) {
        return 0;
    }
    slot->unk88 = 0;
    slot->unk8C = 0;
    id = func_00166760(cursor);
    slot->unk3C = 0;
    cursor += 8;
    if (*(s32 *)cursor == 0) {
        func_001340C0(&slot->unk4, id);
        func_001340C0(&slot->unk68, func_00166760(cursor));
        func_001667C0(cursor + 16);
        r = func_001667C0(cursor + 24);
        slot->unk88 = r;
        slot->unk8C = r;
        D_003E092C++;
        return 1;
    }
    va = func_00166780(cursor);
    vb = func_00166780(cursor + 8);
    func_00166780(cursor + 16);
    vc = func_00166780(cursor + 24);
    func_001340C0(&slot->unk4, id);
    slot->unk34 = va;
    slot->unk38 = vb;
    buf[0] = vc;
    buf[1] = D_003A58E4;
    buf[2] = vc;
    buf[3] = D_003A58EC;
    func_0013C680(buf, D_00415C80, buf);
    slot->unk2C = buf[0];
    slot->unk30 = buf[2];
    slot->unk24 = 0;
    slot->unk26 = 0;
    slot->unk28 = 0x200;
    handle = func_0015F450(buf);
    slot->unk2A = handle;
    slot->unk0 = func_0015AEF0(handle, &slot->unk4, -1);
    D_003E092C++;
    return 1;
}
