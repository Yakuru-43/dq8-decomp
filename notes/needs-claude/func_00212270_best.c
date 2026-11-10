// range: 0x212270 0x212390
#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Item;

typedef struct {
    s32 unk0;
    u8 unk4;
    char pad5[0x1F];
    s32 unk24;
    s32 unk28;
} MsgSlot;

extern MsgSlot *D_003E0948;
extern char D_003E094C;
extern char *D_003A5610[][3];

u32 func_00166760(Item *);
s32 func_001667C0(Item *);
s32 func_00133F78(u32, char *);
void func_001340C0(u8 *, s32);

s32 func_00212270(Item *arg0) {
    Item *items;
    u32 handle;
    s32 i;
    MsgSlot *slot;
    s32 found;
    s32 first;
    s32 second;

    items = arg0;
    items = items + 1;
    slot = &D_003E0948[D_003E094C];
    slot->unk0 = -1;
    handle = func_00166760(arg0);
    if (handle == 0) {
        return 0;
    }
    i = 0;
    while (D_003A5610[i][0] != 0) {
        found = func_00133F78(handle, D_003A5610[i][0]);
        slot->unk0 = i;
        if (found == 0) {
            break;
        }
        i++;
    }
    if (slot->unk0 < 0) {
        return 0;
    }
    slot->unk4 = 0;
    if (items->type != 0) {
        first = func_001667C0(items);
        items = items + 1;
        second = func_001667C0(items);
        slot->unk24 = first - 0x100;
        slot->unk28 = second - 0xE0;
    } else {
        func_001340C0(&slot->unk4, func_00166760(items));
    }
    D_003E094C++;
    return 1;
}
