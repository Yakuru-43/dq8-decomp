// best attempt for func_0026DD00 (structural score=43) — the twin shape,
// static inline helper variant; plain if-nests give the same islands.
// range: 0x26DD00 0x26DDA0
#include "common.h"

typedef struct {
    char pad0[0x20];
    u32 unk20;
    char pad24[4];
    u32 unk28;
    char pad2C[0x18];
    u32 unk44;
    u32 unk48;
    char pad4C[4];
    u32 unk50;
    u32 unk54;
} S_0026DD00;

extern void func_00278570(u32 base, u32 ctx, u32 size);

static inline void Sub_Unload(u32 base, u32 ctx, u32 size) {
    if (size != 0) {
        func_00278570(base, ctx, size);
    }
}

u32 func_0026DD00(u32 arg0, u32 arg1, S_0026DD00 **argp) {
    S_0026DD00 *s;

    s = *argp;
    if (s->unk28 != 0) {
        Sub_Unload(s->unk28, s->unk20, s->unk44);
        Sub_Unload(s->unk28, s->unk20, s->unk50);
        Sub_Unload(s->unk28, s->unk20, s->unk48);
        Sub_Unload(s->unk28, s->unk20, s->unk54);
    }
    s->unk50 = 0;
    s->unk44 = 0;
    s->unk48 = 0;
    s->unk54 = 0;
    return 1;
}
