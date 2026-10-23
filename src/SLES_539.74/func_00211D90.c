// range: 0x211D90 0x211E10
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ f32 unkC;
} MsgEntry;

typedef struct {
    char pad0[0x3C];
    /* 0x3C */ s8 unk3C;
    char pad3D[3];
    /* 0x40 */ MsgEntry entries[2];
} MsgSlot;

extern MsgSlot *D_003E0950;

void func_002127B0(MsgEntry *, char *);

s32 func_00211D90(char *arg0) {
    char *cursor;
    s32 i;

    cursor = arg0;
    if (D_003E0950 == NULL) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        func_002127B0(&D_003E0950->entries[i], cursor);
        cursor += 0x18;
    }
    D_003E0950->unk3C++;
    return 1;
}
