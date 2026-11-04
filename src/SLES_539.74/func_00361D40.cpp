// range: 0x361D40 0x361E60
#include "common.h"

struct ThreadBlock {
    u32 status;
    void (*func)(void);
    void *stack;
    u32 stackSize;
    void *gp;
    s32 param;
    u32 pad18[6];
};

struct Dims {
    s16 f10;
    s16 f12;
    s16 f14;
    s16 f16;
};

struct LoadInfo {
    LoadInfo() {}

    s32 param;
    void *stack;
    u32 stackSize;
    s32 f0C;
    Dims dims;
    s16 f18;
    s32 f1C;
    s32 f20;
    f32 f24;
};

extern "C" {
s32 CreateThread(ThreadBlock *);
s32 func_00117960(s32, s32 *);
void func_00361E60(void);
extern char _gp;
extern s32 D_003E0030;
extern s32 D_003E1408;
extern s32 D_003E140C;
extern s32 D_003E1420;
extern LoadInfo D_00458670;
}

extern "C" s32 func_00361D40(LoadInfo *arg) {
    ThreadBlock th;
    s32 tid;

    th.gp = &_gp;
    th.func = func_00361E60;
    th.stack = arg->stack;
    th.stackSize = arg->stackSize;
    th.param = arg->param;
    tid = CreateThread(&th);
    D_003E0030 = tid;
    D_003E1408 = 1;
    D_003E140C = 0;
    D_003E1420 = 0;
    if (tid > 0) {
        func_00117960(tid, 0);
        D_00458670 = *arg;
        return 1;
    }
    return 0;
}
