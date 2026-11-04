// range: 0x468D30 0x468F50
#include "common.h"

extern void *D_003E1B8C __attribute__((section(".sdata")));
extern M2C_UNK D_421AD0 __attribute__((section(".data")));

extern void *func_168160(void);
extern f32 func_2CB200(s32);
extern s32 func_359620(void *, s32, void **, s32, s32, s32, s32, s32, s64);

s32 func_00468D30(char *self) {
    void *buf[0x20];
    f32 best;
    s32 kind;
    s32 count;
    s32 i;

    func_168160();
    if (*(s32 *)self == 1) {
        kind = (s32)*(f32 *)(self + 4);
    } else {
        kind = *(s32 *)(self + 4);
    }
    best = 100.0f;
    switch (kind) {
    case 1:
        count = func_359620(&D_421AD0, 0, buf, 0x20, 1, 1, 0, -1, 1);
        for (i = 0; i < count; i++) {
            f32 val = func_2CB200(*(s16 *)((char *)buf[i] + 0xC));
            if (best > val) {
                best = val;
            }
        }
        break;
    case 12:
    case 8: {
        void *entry = *(void **)0x42186C;
        if (entry != 0) {
            best = func_2CB200(*(s16 *)((char *)entry + 2));
        }
        break;
    }
    case 9:
        for (i = 0; i < *(s32 *)((char *)D_003E1B8C + 0x90); i++) {
            f32 val = func_2CB200(*(s32 *)((char *)D_003E1B8C + 0x94));
            if (best > val) {
                best = val;
            }
        }
        break;
    case 13:
        if (*(s32 *)((char *)D_003E1B8C + 0x90) > 0) {
            best = func_2CB200(*(s32 *)((char *)D_003E1B8C + 0x94));
        }
        break;
    case 2:
        count = func_359620(&D_421AD0, 1, buf, 0x20, 1, 1, 0, -1, 1);
        for (i = 0; i < count; i++) {
            f32 val = func_2CB200(*(s16 *)((char *)buf[i] + 0xC));
            if (best > val) {
                best = val;
            }
        }
        break;
    default:
        best = 0.0f;
        break;
    }
    if (*(s32 *)(self + 8) == 3) {
        *(f32 *)(*(s32 *)(self + 0xC) + 4) = best;
    }
    return 1;
}
