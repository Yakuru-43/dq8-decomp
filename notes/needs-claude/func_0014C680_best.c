// Best attempt (switch, cases written 2 then 1): CLASS reorder+register
// score=4, 144 vs 144 bytes. Swap the two cases and the diff moves: then the
// case *bodies* swap instead (tests print in reverse source order, bodies in
// source order), so one switch cannot give both orders. See the .md note.
// range: 0x14C680 0x14C710
#include "common.h"

s32 func_0014C680(u32 *arg0, s32 arg1) {
    u32 obj;
    s32 valid;
    s32 count;
    u32 node;
    s32 i;

    obj = *arg0;
    valid = obj != 0;
    if (valid == 0) {
        return 0;
    }
    switch (arg1) {
    default:
        count = *(s32 *)(obj + 0x2C);
        if (count == 0) {
            return 0;
        }
        node = *(u32 *)(obj + 0x30);
        i = 0;
        while (i < count) {
            if (*(s32 *)(node + 4) == arg1) {
                return *(s32 *)(node + 0xC);
            }
            node = *(u32 *)node;
            i++;
        }
        return 0;
    case 2:
        if (valid != 0) {
            return *(s32 *)(obj + 0x28);
        }
        return 0;
    case 1:
        if (valid != 0) {
            return *(s32 *)(obj + 0x20);
        }
        return 0;
    }
}
