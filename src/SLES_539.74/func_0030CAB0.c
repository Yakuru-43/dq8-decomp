// range: 0x30CAB0 0x30CB70
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern s32 func_00359620(M2C_UNK *, s32, void *, s32, s32, s32, s32, s32, s32);
s32 func_00296F80(void *arg0);              /* extern */
M2C_UNK func_00356910(s32, s32);            /* extern */

void func_0030CAB0(s32 arg0) {
    void *work[0x20];
    s32 count;
    s32 best;
    s32 i;
    s32 score;

    best = 0;
    count = func_00359620(&D_00421AD0, 1, work, 0x20, 1, 0, 0, -1, 0);
    for (i = 0; i < count; i++) {
        if (work[i] != 0) {
            score = func_00296F80(work[i]);
            if (best < score) {
                best = score;
            }
        }
    }
    func_00356910(arg0, best);
}
