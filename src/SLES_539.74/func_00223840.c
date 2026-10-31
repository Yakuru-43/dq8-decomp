// range: 0x223840 0x223890
#include "common.h"

extern s32 *D_003E0A0C;

char *func_00223840(s32 arg0) {
    s32 *tbl;
    s32 n;
    s32 i;
    char *temp_v1;

    tbl = D_003E0A0C;
    if (tbl != 0) {
        n = tbl[0];
        for (i = 0; i < n; i++) {
            temp_v1 = (char *)tbl + (i << 5);
            if (*(s16 *)(temp_v1 + 0x30) == arg0) {
                return temp_v1 + 0x30;
            }
        }
    }
    return 0;
}
