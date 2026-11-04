// range: 0x15F6A0 0x15F7E0
#include "common.h"

typedef struct {
    u32 pad00;
    u32 initial;
    u32 current;
    u32 pad0C[2];
    u32 f14;
} SemaBlock;

typedef struct {
    u8 low : 6;
    u8 on : 1;
    u8 high : 1;
} Ent;

extern s32 D_003DFB80;
extern s32 D_003DFB84;
extern s32 D_003E029C;
extern s32 D_003E02A0;
extern s32 D_003E02A4;
extern u8 D_003E02AC;
extern s32 D_003E02B0;

s32 WaitSema(s32);
s32 SignalSema(s32);
s32 CreateSema(SemaBlock *);
void FlushCache(s32);
s32 AddIntcHandler(s32, void (*)(s32), s32);
Ent *func_00109F98(s32);
void func_0010A2C8(Ent *, void *);
void func_00117368(s32);
void func_0015F7E0(s32);

void func_0015F6A0(void *arg) {
    SemaBlock sm;
    Ent *e;
    s32 id;

    id = D_003DFB80;
    WaitSema(id);
    if (D_003E02AC == 0 || D_003E02B0 != 0) {
        if (D_003E02A0 == 0) {
            e = func_00109F98(1);
            D_003E02A4 = 0;
            e->on = 1;
            FlushCache(0);
            func_0010A2C8(e, arg);
            sm.initial = 1;
            sm.current = 0;
            sm.f14 = 0;
            D_003DFB84 = CreateSema(&sm);
            D_003E02A0 = 1;
            D_003E029C = AddIntcHandler(5, func_0015F7E0, -1);
            func_00117368(5);
            SignalSema(id);
        } else {
            SignalSema(id);
        }
    } else {
        D_003E02B0 = (s32)arg;
        SignalSema(id);
    }
}
