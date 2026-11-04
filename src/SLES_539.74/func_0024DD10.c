// range: 0x24DD10 0x24DE20
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

extern char _gp;
extern s32 D_003DFD74;
extern s32 D_003E0BA0;
extern s32 D_003E0BA4;
extern s32 D_003E0BA8;
extern u8 D_003E0BAC;
extern u8 D_0041B960 __attribute__((section(".data")));
extern s32 D_0041B964 __attribute__((section(".data")));
extern s32 D_0041B968 __attribute__((section(".data")));
extern u8 D_0041B160[];

s32 CreateSema(SemaBlock *);
s32 CreateThread(ThreadBlock *);
s32 func_00117960(s32, s32 *);
void func_0024DE20(void);

void func_0024DD10(s32 param) {
    SemaBlock sm;
    ThreadBlock th;
    s32 sema;

    D_003E0BA0 = -1;
    D_003E0BA4 = -1;
    D_003E0BAC = 1;
    D_0041B960 = 1;
    sm.initial = 1;
    D_0041B964 = 0;
    sm.f14 = 0;
    D_0041B968 = 0;
    sm.current = 0;
    sema = CreateSema(&sm);
    D_003E0BA4 = sema;
    sm.current = 1;
    sema = CreateSema(&sm);
    D_003E0BA0 = sema;
    th.stackSize = 0x800;
    th.gp = &_gp;
    th.param = param;
    th.func = func_0024DE20;
    th.stack = D_0041B160;
    sema = CreateThread(&th);
    D_003E0BA8 = sema;
    func_00117960(sema, 0);
    if (D_003E0BA0 < 0) {
        goto fail;
    }
    if (D_003E0BA0 < 0) {
        goto fail;
    }
    if (D_003E0BA8 >= 0) {
        return;
    }
fail:
    while (D_003DFD74 != 0) {
    }
}
