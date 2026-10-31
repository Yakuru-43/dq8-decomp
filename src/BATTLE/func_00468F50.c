// range: 0x468F50 0x469050
#include "common.h"

extern void *D_003E1B8C __attribute__((section(".sdata")));

extern void *func_168160(void);
extern f32 func_2CB270(void *, void *);

s32 func_00468F50(char *self) {
    void *work;
    f32 best;
    s32 kind;
    s32 i;

    work = func_168160();
    if (*(s32 *)self == 1) {
        kind = (s32)*(f32 *)(self + 4);
    } else {
        kind = *(s32 *)(self + 4);
    }
    best = 0.0f;
    switch (kind) {
    case 13:
        if (*(s32 *)((char *)D_003E1B8C + 0x90) > 0) {
            best = func_2CB270(work, *(void **)((char *)D_003E1B8C + 0x94));
        }
        break;
    case 9:
        i = 0;
        while (i < *(s32 *)((char *)D_003E1B8C + 0x90)) {
            f32 val = func_2CB270(work, *(void **)((char *)D_003E1B8C + i * 4 + 0x94));
            if (best < val) {
                best = val;
            }
            i++;
        }
        break;
    }
    if (*(s32 *)(self + 8) == 3) {
        *(f32 *)(*(s32 *)(self + 0xC) + 4) = best;
    }
    return 1;
}
