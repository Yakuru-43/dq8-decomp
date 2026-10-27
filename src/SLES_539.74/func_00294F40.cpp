// range: 0x294F40 0x295030
#include "common.h"

typedef struct S_358 {
    char pad0[0x358];
    u32 unk358;
} S_358;

typedef struct S_Node {
    char pad0[0x3];
    u8 unk3;
    char pad4[0xC];
    u16 unk10;
    char pad12[0x6];
    struct S_Node *unk18;
    S_358 *unk1C;
} S_Node;

typedef struct {
    char pad0[0x448];
    S_Node head;
} S_arg0;

extern "C" {

s32 func_00292C60(S_arg0 *);
s32 func_0029CCC0(S_arg0 *, S_Node *);
s32 func_0029CD30(S_arg0 *, S_Node *);
s32 func_00295030(S_arg0 *);

s32 func_00294F40(S_arg0 *arg0) {
    bool found;
    s32 handle;
    S_Node *node;

    found = false;
    handle = func_00292C60(arg0);
    node = &arg0->head;
    while ((node = node->unk18) != 0) {
        if (node->unk10 == 0xFFFF) {
            break;
        }
        if (node->unk3 != 0) {
            if (handle == 0) {
                if (func_0029CCC0(arg0, node) != 0 && (node->unk1C->unk358 & 4)) {
                    found = true;
                    break;
                }
            } else {
                if (func_0029CD30(arg0, node) != 0 && (node->unk1C->unk358 & 4)) {
                    found = true;
                    break;
                }
            }
        }
    }
    if (found) {
        return func_00295030(arg0);
    }
    return 0;
}

}
