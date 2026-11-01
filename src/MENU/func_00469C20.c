// range: 0x469C20 0x469C70
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_00469C20(s32 n, s32 *row, s32 *col) {
    s32 r = n / 3;
    s32 c = n % 3;
    s32 cell = r + c * 4;

    if (row != NULL) {
        *row = r;
    }
    if (col != NULL) {
        *col = c;
    }
    return cell;
}
