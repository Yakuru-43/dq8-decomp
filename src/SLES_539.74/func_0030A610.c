// range: 0x30A610 0x30A720
#include "common.h"

extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern s32 func_00359620(M2C_UNK *, s32, void *, s32, s32, s32, s32, s32, s32);
s32 func_00297090(void *arg0);                        /* extern */
M2C_UNK func_00356910(s32, s32);                      /* extern */
s32 func_0030A720(s32 *arg0);                         /* extern */
s32 func_0030A730(void *arg0);                        /* extern */

typedef struct {
    char pad0[0x114];
    s32 unk114;
    char pad118[0x134 - 0x118];
    s32 *unk134;
    void *unk138;
} S_arg1;

void func_0030A610(s32 arg0, S_arg1 *arg1) {
    void *work[0x20];
    s32 count;
    s32 i;
    s32 best;
    s32 score;

    if ((arg1->unk114 != 0) && (func_0030A730(arg1->unk138) != 0)) {
        best = 0;
        count = func_00359620(&D_00421AD0, 1, work, 0x20, 1, 0, 0, -1, 1);
        for (i = 0; i < count; i++) {
            if (work[i] != 0) {
                score = func_00297090(work[i]);
                if (best < score) {
                    best = score;
                }
            }
        }
        if (func_0030A720(arg1->unk134) >= best) {
            func_00356910(arg0, 1);
            return;
        }
    }
    func_00356910(arg0, 0);
}
