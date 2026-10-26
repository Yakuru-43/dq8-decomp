// range: 0x291830 0x291950
#include "common.h"

typedef struct S_560 {
    char pad0[0x560];
    u8 unk560;
} S_560;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    u8 unk4;
    char pad5[0xB];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    union {
        S_560 *obj;
        u32 objVal;
    } unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
    char pad468[0x128];
    s32 unk590[6];
} S_arg0;

s32 func_00297090();                             /* extern */
s32 func_002970A0();                             /* extern */

/* recount the running nodes; a node stops running when its two group
   scores leave it behind, otherwise its kind's counter grows */
void func_00291830(S_arg0 *arg0, s32 arg1, s32 arg2) {
    S_Node *node;
    S_560 *obj;
    s32 left;
    s32 i;

    for (i = 0; i < 6; i++) {
        arg0->unk590[i] = 0;
    }
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            return;
        }
        node->unk4 = node->unk3;
        if (node->unk3 != 0) {
            obj = node->unk1C.obj;
            if (obj != 0 && obj->unk560 == 1) {
                node->unk3 = 0;
            } else {
                left = arg2 * func_00297090(node->unk1C.objVal);
                if (left >= arg1 * func_002970A0(obj)) {
                    node->unk3 = 0;
                } else {
                    arg0->unk590[node->unk10 >> 8]++;
                }
            }
        }
    }
}
