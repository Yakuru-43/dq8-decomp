// range: 0x46B840 0x46B8D0
#include "common.h"

s32 func_0046DE00(void);
s32 func_2B1DB0(s32);
s32 func_0046DCE0(void);
extern s16 D_003E19F0;
extern void func_371050(void *arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_370E00(void *arg0, s32 arg1, s32 arg2);
extern void func_371100(void *arg0, s32 arg1);

typedef struct {
    char pad0[0x18];
    void *unk18;
    char pad1[4];
    void *unk20;
} S_arg0;

void func_0046B840(S_arg0 *arg0) {
    s32 min;
    s32 val;

    D_003E19F0 = func_2B1DB0(func_0046DE00());
    min = func_0046DCE0();
    val = D_003E19F0;
    if (val <= min) {
        min = val;
    }
    if (arg0 != 0) {
        func_371050(arg0, 1, min - 1, val - 1);
        if (arg0->unk20 != 0) {
            func_370E00(arg0->unk20, *(s16 *)((char *)arg0->unk18 + 0xE), 0);
        }
        func_371100(arg0, 0);
    }
}
