// range: 0x466FA0 0x467030
#include "common.h"

typedef struct {
    char pad0[0xA];
    s16 unkA;
} S_18;

s32 func_370E00(void *, s32, s32);                         /* extern */
s32 func_3715D0(S_18 *);                                   /* extern */
M2C_UNK func_2D6710(s32, s32, s32, s32, s32, s32, s32, f32); /* extern */
void func_004671D0(s32);                                   /* extern */
extern f32 D_003DF744 __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x18];
    S_18 *unk18;
    char pad1C[4];
    void *unk20;
} S_arg0;

s32 func_00466FA0(S_arg0 *arg0, s32 arg1) {
    func_370E00(arg0->unk20, arg0->unk18->unkA, 0);
    func_2D6710(arg1, 0x58F, func_3715D0(arg0->unk18), 0x18703, -0x21, -2, 0,
                D_003DF744);
    func_004671D0(func_3715D0(arg0->unk18));
    return 1;
}
