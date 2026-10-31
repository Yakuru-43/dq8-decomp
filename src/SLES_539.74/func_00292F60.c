// range: 0x292F60 0x293080
#include "common.h"

typedef struct S_Obj {
    char pad0[0x10];
    s16 unk10;
    s16 unk12;
} S_Obj;

typedef struct S_Target {
    char pad0[0xF0];
    s32 unkF0;
    s32 unkF4;
} S_Target;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_Obj *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x124];
    S_Target *unk58C;
} S_arg0;

extern s32 func_00201740(void *arg0, s32 *arg1);
extern s32 func_002016A0(void *arg0);
extern void func_00292960(S_arg0 *arg0);

/* pick the running node with the biggest gain over its current value,
   copy its position to the target and drop the others */
s32 func_00292F60(S_arg0 *arg0) {
    s32 best;
    S_Node *chosen;
    S_Node *node;
    S_Obj *obj;
    s32 gain;

    if (func_00201740(arg0->unk58C, 0) <= 0) {
        return 0;
    }
    func_00292960(arg0);
    best = 0;
    chosen = 0;
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        if (node->unk3 == 0) {
            continue;
        }
        obj = node->unk1C;
        if (obj == (S_Obj *)arg0->unk58C) {
            node->unk3 = 0;
            continue;
        }
        gain = func_002016A0(node->unk1C) - func_00201740(obj, 0);
        if (gain <= 0) {
            node->unk3 = 0;
            continue;
        }
        if (best < gain) {
            best = gain;
            arg0->unk58C->unkF0 = node->unk1C->unk10;
            arg0->unk58C->unkF4 = node->unk1C->unk12;
            if (chosen) {
                chosen->unk3 = 0;
            }
            chosen = node;
        }
    }
    if (best > 0) {
        return 1;
    }
    return 0;
}
