// CLASS structural score=67 (67 words differ, 296 vs 296 bytes) — best attempt (2),
// `-- -O3 -flag divbyzerocheck`. Attempt 1 (plain s32 sema, no pointer local): score 59,
// 288 bytes — every guard CSE'd to `lw a0,0xC(s0); bgtz a0`, no spill slots.
// Attempt 3 (static inline volatile s32 *SemaP(CountSem *) helper instead of the local):
// score 59, back to 288 bytes, guard 0 became bgtzl again.
// range: 0x2510D0 0x251200
#include "common.h"

typedef struct {
    u32 pad00;
    u32 initial;
    u32 current;
    u32 pad0C[2];
    u32 f14;
} SemaBlock;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    volatile s32 sema; // thread-shared: the worker signals it
    s32 f10;
    s32 f14;
    u8 f18;
    u8 f19;
    u8 f1A;
    u8 pad1B;
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 f28;
    u8 pad29[3];
    s32 f2C;
    s32 f30;
} CountSem;

extern void DebugPrintf(char *, s32);
extern char D_003C8F00[] __attribute__((section(".data")));
s32 CreateSema(SemaBlock *);
M2C_UNK SignalSema(s32);
M2C_UNK WaitSema(s32);

void func_002510D0(CountSem *cs, s32 value, u32 size) {
    SemaBlock sm;
    volatile s32 *id;

    cs->f04 = value;
    cs->f08 = cs->f00 * (size / cs->f00);
    if (cs->sema <= 0) {
        sm.initial = 1;
        sm.current = 1;
        sm.f14 = 0;
        cs->sema = CreateSema(&sm);
        DebugPrintf(D_003C8F00, cs->sema);
    }
    cs->f10 = 0;
    id = &cs->sema;
    cs->f14 = 0;
    cs->f18 = 1;
    cs->f1A = 0;
    cs->f19 = 0;
    cs->f20 = 0;
    cs->f1C = 0;
    if (cs->sema > 0) {
        WaitSema(*id);
    }
    cs->f24 = 0;
    if (*id > 0) {
        SignalSema(*id);
    }
    if (cs->sema > 0) {
        WaitSema(*id);
    }
    cs->f28 = 0;
    cs->f2C = 0;
    cs->f30 = 0;
    if (*id > 0) {
        SignalSema(*id);
    }
}
