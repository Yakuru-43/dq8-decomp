// CLASS structural score=10 (10 words differ, 92 vs 92 bytes) — best of 5 attempts
// range: 0x29CC60 0x29CCC0
#include "common.h"

struct AiNode {
    char pad0[0x10];
    u16 unk10;
};

struct AiEntry {
    /* 0x00 */ u8 kind;
    /* 0x01 */ u8 flag1;
    /* 0x02 */ u8 flag2;
    char pad03[0x19];
    /* 0x1C */ struct AiNode *node;
};

extern s32 func_00297090(void *, void *);

s32 func_0029CC60(s32 arg0, struct AiEntry *arg1) {
    struct AiNode *node;
    s32 ret;

    if (arg1->kind == 0) {
        return 0;
    }
    if (arg1->flag1 != 0) {
        return 0;
    }
    if (arg1->flag2 != 0) {
        return 0;
    }
    node = arg1->node;
    if (node->unk10 == 0) {
        ret = func_00297090(node, arg1) > 0;
    } else {
        ret = 0;
    }
    return ret;
}
