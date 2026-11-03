// range: 0x468E70 0x469000
// flags: -flag divbyzerocheck
#include "common.h"

s32 func_132D38(void);

typedef struct {
    s32 field_00;
    s32 field_04;
    s32 pad_08[8];
} S_bar; /* 0x28 */

s32 func_00468E70(char *arg0) {
    S_bar *bars;
    s32 *pool;
    s32 k;
    s32 m;
    s32 size;
    s32 buf[5][125];
    s32 counter;
    s32 i;
    s32 j;
    s32 cnt;
    s32 r;

    counter = 1;
    for (i = 0; i < 5; i++) {
        if (i == 2) {
            cnt = 4;
        } else {
            cnt = 5;
        }
        for (j = 0; j < cnt; j++) {
            buf[i][j] = counter;
            counter = counter + 1;
        }
    }
    for (k = 0; k < 5; k++) {
        if (k == 2) {
            size = 4;
        } else {
            size = 5;
        }
        for (m = 0; m < 5; m++) {
            if (k == 2 && m == 2) {
                continue;
            }
            pool = buf[k];
            bars = (S_bar *)(arg0 + 8 * k);
            r = func_132D38() % size;
            bars[m].field_00 = pool[r];
            bars[m].field_04 = 0;
            while (r < size) {
                pool[r] = pool[r + 1];
                r = r + 1;
            }
            size = size - 1;
        }
    }
    return 1;
}
