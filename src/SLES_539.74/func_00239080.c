// range: 0x239080 0x239180
#include "common.h"

extern void DebugPrintf(char *fmt, ...);

extern char D_003C8720[]; /* "dng_effect same ext_func_no!!![%d]\n" */
extern char D_003C8750[]; /* "dng_effect ext func over!!\n" */

struct DngEffect {
    void *func;
    s32 ext_func_no;
};

extern struct DngEffect D_003A6770[];
extern s32 D_004162F0[0x100];

void func_00239080(void) {
    s32 i;
    s32 j;
    s32 k;
    struct DngEffect *e;

    for (i = 0; i < 0x100; i++) {
        D_004162F0[i] = 0;
    }
    for (j = 0;; j++) {
        e = &D_003A6770[j];
        if (e->func == 0) {
            return;
        }
        for (k = 0; k < j; k++) {
            if (e->ext_func_no == D_003A6770[k].ext_func_no) {
                DebugPrintf(D_003C8720, D_003A6770[k].ext_func_no);
                while (1) {}
            }
        }
        if (e->ext_func_no < 0 || e->ext_func_no >= 0x100) {
            DebugPrintf(D_003C8750);
        } else {
            D_004162F0[e->ext_func_no] = (s32)e->func;
        }
    }
}
