// range: 0x296930 0x2969F0
#include "common.h"

typedef struct {
    char pad0[0x10];
    s16 unk10;
    s16 unk12;
} S_Obj;

typedef struct S_Node2 {
    char pad0[0x3];
    u8 unk3;
    char pad4[0x10];
    struct S_Node2 *unk14;
    char pad18[0x4];
    S_Obj *unk1C;
} S_Node2;

typedef struct {
    char pad0[0x10];
    s32 sel10;
    s32 sel14;
} S_Entry;

typedef struct {
    char pad0[0xE0];
    S_Entry entry;
} S_58C;

typedef struct {
    char pad0[0x468];
    S_Node2 head;
    char pad488[0x104];
    S_58C *unk58C;
} S_arg0;

M2C_UNK func_00292960(S_arg0 *);                     /* extern */
M2C_UNK func_00292610(S_arg0 *, s32);                /* extern */

s32 func_00296930(S_arg0 *arg0) {
    S_Entry *sel;
    S_Node2 *node;
    s32 i;

    sel = &arg0->unk58C->entry;
    func_00292960(arg0);
    for (i = 0; i < 6; i++) {
        if (i != sel->sel10) {
            func_00292610(arg0, i);
        }
    }
    node = &arg0->head;
    while ((node = node->unk14) != 0) {
        if (node->unk3 != 0) {
            sel->sel10 = node->unk1C->unk10;
            sel->sel14 = node->unk1C->unk12;
            return 1;
        }
    }
    return 0;
}
