// range: 0x294000 0x2940F0
#include "common.h"

typedef struct S_560 {
    char pad0[0x10];
    s16 unk10;
    char pad12[0x54E];
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
    S_560 *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
} S_arg0;

M2C_UNK func_00292960(S_arg0 *);                    /* extern */
M2C_UNK func_002914D0(S_arg0 *);                    /* extern */
s64 func_0035DE00(void *);                           /* extern */

s32 func_00294000(S_arg0 *arg0) {
    u8 flag;
    S_Node *node;
    s64 ret;

    func_00292960(arg0);
    flag = 0;
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        node->unk4 = node->unk3;
        if (node->unk3 != 0 && node->unk1C->unk10 == 1) {
            if ((ret = (s64) (s8) func_0035DE00(node->unk1C)) == 1 ||
                (ret = (s64) (s8) func_0035DE00(node->unk1C)) == 3) {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) {
        func_002914D0(arg0);
        return 1;
    }
    return 0;
}
