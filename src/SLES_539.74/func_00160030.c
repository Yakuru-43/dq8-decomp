// range: 0x160030 0x160110
#include "common.h"

typedef struct {
    u32 pad00;
    u32 initial;
    u32 current;
    u32 pad0C[2];
    u32 f14;
} SemaBlock;

typedef struct {
    u32 status;
    void *func;
    void *stack;
    u32 stackSize;
    void *gp;
    s32 param;
    u32 pad18[6];
} ThreadBlock;

extern s32 D_003DFBB4;
extern s32 D_003DFBB8;
extern s32 D_003E0328;
extern s32 D_003E0330;
extern s32 D_003E0334;
extern s32 D_003E0338;
extern char _gp;
extern u8 D_003F8A80[];

s32 CreateSema(SemaBlock *);
s32 CreateThread(ThreadBlock *);
void DeleteSema(s32);
s32 func_00117960(s32, s32 *);
s32 func_0012A520(void (*)(void), s32);
void func_0015FE40(void);
void func_00160110(void);

s32 func_00160030(s32 param) {
    SemaBlock sm;
    ThreadBlock th;
    s32 sema;
    s32 tid;

    if (D_003E0328 != 0) {
        return 0;
    }
    sm.initial = 1;
    sm.current = 0;
    sm.f14 = 0;
    sema = CreateSema(&sm);
    D_003DFBB8 = sema;
    if (sema < 0) {
        return 0;
    }
    th.stackSize = 0x2000;
    th.param = param;
    th.gp = &_gp;
    th.func = func_0015FE40;
    th.stack = D_003F8A80;
    tid = CreateThread(&th);
    D_003DFBB4 = tid;
    if (tid < 0) {
        DeleteSema(D_003DFBB8);
        return 0;
    }
    D_003E0330 = 0;
    D_003E0328 = 1;
    D_003E0334 = 0;
    D_003E0338 = 0;
    func_00117960(tid, 0);
    func_0012A520(func_00160110, 0);
    return 1;
}
