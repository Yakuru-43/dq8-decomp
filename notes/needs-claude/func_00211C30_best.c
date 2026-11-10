// range: 0x211C30 0x211D50
// best draft (attempt 2 of session factory-2 2026-10-23): score=61
// (attempt 1 scored 58 but emitted beqz+nop for the loop exit; this one gets
//  the correct beql + delay-slot store, so it is the better starting point)
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} MsgArg;

typedef struct {
    char pad0[0x20];
    s32 unk20;
    s32 unk24;
    s32 unk28;
} MsgEntry;

s32 func_00166760(MsgArg *);                          /* extern */
s32 func_001667C0(MsgArg *);                          /* extern */
s32 func_00133F78(s32, M2C_UNK *);                    /* extern */
void func_001340C0(MsgEntry *, s32);                  /* extern */

extern M2C_UNK *D_003A55B0[];
extern s16 D_003E0938;
extern MsgEntry *D_003E093C;

s32 func_00211C30(MsgArg *arg0) {
    MsgArg *cursor;
    s32 handle;
    s32 chosen;
    s32 obj;
    s32 idx;
    s32 value;
    s32 value2;
    MsgEntry *entry;

    handle = func_00166760(arg0);
    cursor = arg0 + 1;
    chosen = 0;
    if (cursor->unk0 != 0) {
        chosen = func_001667C0(cursor);
        cursor += 1;
    } else {
        obj = func_00166760(cursor);
        cursor += 1;
        for (idx = 0; D_003A55B0[idx] != 0; idx++) {
            if (func_00133F78(obj, D_003A55B0[idx]) == 0) {
                chosen = idx;
                break;
            }
        }
    }
    value = func_001667C0(cursor);
    cursor += 1;
    value2 = func_001667C0(cursor);
    entry = &D_003E093C[D_003E0938];
    func_001340C0(entry, handle);
    entry->unk20 = chosen;
    entry->unk24 = value;
    entry->unk28 = value2;
    D_003E0938++;
    return 1;
}
