// range: 0x210FD0 0x211050
#include "common.h"

extern s16 *D_003E0958;
extern s16 *D_003E095C;

s32 func_00210FD0(s32 key) {
    s16 *tbl;
    s32 n;
    s32 i;

    tbl = D_003E0958;
    if (tbl != 0) {
        n = tbl[0];
        for (i = 0; i < n; i++) {
            if (key == tbl[i + 1]) {
                return 1;
            }
        }
    }
    tbl = D_003E095C;
    if (tbl != 0) {
        n = tbl[0];
        for (i = 0; i < n; i++) {
            if (key == tbl[i + 1]) {
                return 2;
            }
        }
    }
    return 0;
}
