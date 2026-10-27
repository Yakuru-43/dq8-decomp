// range: 0x218C50 0x218D10
#include "common.h"

s32 func_002186B0(s32);                                /* extern */
s32 func_00218D10(s32);                                /* extern */
s32 func_0018F100(s32);                                /* extern */
extern s32 D_003E09A4;
extern s32 D_003E09A8;

s32 func_00218C50(s32 arg0) {
    s32 node;
    s32 rec;
    s32 arr;
    s32 elem;
    s32 index;

    node = D_003E09A8;
    if (node != 0) {
        while (node != 0) {
            rec = func_002186B0(node);
            if (rec != 0) {
                if (M2C_FIELD(rec, s32 *, 0) == arg0) {
                    return M2C_FIELD(rec, s32 *, 4);
                }
            }
            node = func_00218D10(node);
        }
    }
    arr = D_003E09A4;
    if (arr != 0) {
        elem = arr + 0x10;
        index = 0;
        while (index < M2C_FIELD(arr, s32 *, 0)) {
            if (M2C_FIELD(elem, s32 *, 0) == arg0) {
                return elem + 4;
            }
            index++;
            elem += 0x20;
        }
    }
    return func_0018F100(arg0);
}
