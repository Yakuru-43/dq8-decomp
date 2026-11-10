// CLASS structural score=12 (12 words differ, 92 vs 92 bytes) — best of 8 attempts
// range: 0x29CDA0 0x29CE00
#include "common.h"

s32 func_00297090(); /* extern */

s32 func_0029CDA0(u8 *arg0, void *arg1) {
    u8 *v1;
    u8 *node;

    v1 = *(u8 **)(arg0 + 0x488);
    if (v1[0] == 0) {
        return 0;
    }
    if (v1[1] != 0) {
        return 0;
    }
    node = *(u8 **)(v1 + 0x1C);
    if (*(s32 *)(node + 0x140) < *(s32 *)(node + 0x144)) {
        return func_00297090(node, arg1) > 0;
    }
    return 0;
}
