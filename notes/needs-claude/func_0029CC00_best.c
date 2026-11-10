// CLASS structural score=8 (8 words differ, 96 vs 96 bytes)  — best of 8 attempts
// range: 0x29CC00 0x29CC60
#include "common.h"

extern int func_00297090(void *, void *);

s32 func_0029CC00(s32 arg0, u8 *arg1) {
    u8 *node;

    if (arg1[0] == 0) {
        return 0;
    }
    if (arg1[1] != 0) {
        return 0;
    }
    if (arg1[2] == 0) {
        node = *(u8 **)(arg1 + 0x1C);
        if (*(s16 *)(node + 0x10) == 1) {
            return func_00297090(node, arg1) > 0;
        }
    }
    return 0;
}
