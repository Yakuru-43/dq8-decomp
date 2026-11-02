// range: 0x15F6A0 0x15F7E0
// best attempt: CLASS structural score=69 (56 words differ, 256 vs 308 bytes)
// (draft 2: no id local, plain u8 byte RMW; frame -0x60, saves $s0..$s2)
#include "common.h"

typedef struct {
    u32 pad00;
    u32 initial;
    u32 current;
    u32 pad0C[2];
    u32 f14;
} SemaBlock;

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
void *func_00109F98(s32);
void func_0010A2C8(u8 *, void *);
void func_00117368(s32);
void func_0015F7E0(s32);

void func_0015F6A0(void *arg) {
    SemaBlock sm;
    u8 *e;
    s32 b;

    WaitSema(D_003DFB80);
    if (D_003E02AC != 0) {
        if (D_003E02B0 == 0) {
            D_003E02B0 = (s32)arg;
            SignalSema(D_003DFB80);
            return;
        }
    }
    if (D_003E02A0 != 0) {
        SignalSema(D_003DFB80);
        return;
    }
    e = (u8 *)func_00109F98(1);
    b = *e;
    FlushCache(0);
    *e = (b & ~0x40) | 0x40;
    func_0010A2C8(e, arg);
    sm.initial = 1;
    sm.current = 0;
    sm.f14 = 0;
    D_003DFB84 = CreateSema(&sm);
    D_003E02A0 = 1;
    D_003E029C = AddIntcHandler(5, func_0015F7E0, -1);
    func_00117368(5);
    SignalSema(D_003DFB80);
}
