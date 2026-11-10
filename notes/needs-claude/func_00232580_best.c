// range: 0x232580 0x232660
#include "common.h"

void func_00232580(char *arg0, s32 arg1) {
    char *rec;
    s32 i;
    s16 want;
    char *cand;
    s32 j;
    s32 k;

    if (arg1 < 0) {
        arg1 = *(s16 *)(arg0 + 0x1A);
    }
    rec = *(char **)(arg0 + 4);
    for (i = 0; i < *(s32 *)arg0; i++) {
        if (*(s16 *)(rec + 6) == arg1) {
            want = *(s16 *)(rec + 4);
            for (j = 0; j < *(s32 *)arg0; j++) {
                cand = *(char **)(arg0 + 4) + (j * 0x80C);
                if (cand == 0 || *(s16 *)(cand + 4) != want) {
                    cand = 0;
                    continue;
                }
                break;
            }
            if (cand != 0) {
                *(s32 *)cand = 0;
                *(s16 *)(cand + 6) = -1;
                *(s16 *)(cand + 4) = -1;
                for (k = 0; k < 0x200; k++) {
                    *(s32 *)(cand + 0xC + (k * 4)) = 0;
                }
            }
        }
        rec += 0x80C;
    }
}
