// best C for func_0024E7F0 (never matched); CLASS structural score=28 (180 vs 184 bytes)
// range: 0x24E7F0 0x24E8B0
#include "common.h"

void WaitSema(s32);
void SignalSema(s32);

extern s32 D_003E0B80;
extern s32 D_003E0B88;
extern s32 D_003E0B94;
extern s32 D_003E0B98;
extern s32 D_003E0B9C;
extern s32 (*D_003A6D10[0x27])(void *);
extern s32 D_0041B100;

void func_0024E7F0(void) {
    s32 done;
    s32 idx;
    s32 (*fn)(void *);

    done = 0;
    D_003E0B98 = 1;
    while (!(done) != 0) {
        WaitSema(D_003E0B80);
        idx = D_003E0B94;
        D_003E0B9C = 0;
        if (idx > 0) {
            if (idx < 0x27) {
                fn = D_003A6D10[idx];
                if (fn != 0) {
                    D_003E0B9C = fn(&D_0041B100);
                }
            }
        }
        if (D_003E0B94 == -1) {
            done++;
        }
        SignalSema(D_003E0B88);
    }
    D_003E0B98 = 2;
}
