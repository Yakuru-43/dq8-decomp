// range: 0x17A510 0x17A610
// BEST DRAFT (not matched — register-only diff), see func_0017A510.md
#include "common.h"

struct Dims {
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
};

struct LoadInfo {
    s32 param;
    void *stack;
    u32 stackSize;
    s32 f0C;
    struct Dims dims;
    s16 f18;
    s32 f1C;
    s32 f20;
    f32 f24;
};

M2C_UNK DebugPrintf(M2C_UNK *, M2C_UNK *);
void *func_00361CA0(void *);
s32 func_00167960(void);
s32 func_00361D40(struct LoadInfo *);
extern M2C_UNK D_003C2C80 __attribute__((section(".data")));
extern M2C_UNK D_003C2CC0 __attribute__((section(".data")));
extern s32 D_003DFB8C;
extern s8 D_003E041C;
extern s32 D_003E0498;
extern s32 D_003E049C;

s32 func_0017A510(void *stack, u32 stackSize, s32 arg2, f32 arg3) {
    s32 count;
    struct LoadInfo info;

    if (D_003E0498 == 0) {
        return 0;
    }
    if (D_003E041C != 0) {
        D_003E041C = 0;
        return 0;
    }
    DebugPrintf(&D_003C2CC0, &D_003C2C80);
    func_00361CA0(&info);
    info.stackSize = stackSize;
    info.f18 = 1;
    info.f24 = arg3;
    info.dims.f10 = 0x100;
    info.f20 = arg2;
    info.stack = stack;
    info.f1C = 0;
    info.param = D_003DFB8C;
    info.f0C = D_003E049C;
    count = func_00167960();
    info.dims.f12 = count - 0x3E;
    info.dims.f14 = info.dims.f10 + 0x100;
    info.dims.f16 = info.dims.f12 + 0x20;
    func_00361D40(&info);
    return 1;
}
