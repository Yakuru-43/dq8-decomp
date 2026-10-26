// factory-3 plain-C draft for func_003108A0 (try_match CLASS structural 102 —
// worse than the .cpp draft in the note; kept for the callee-typing lessons).
// range: 0x3108A0 0x310A40
#include "common.h"

struct Vt {
    char pad0[0x5C];
    void (*func)(struct Script *);
};

struct Script {
    char pad0[0x1B0];
    struct Vt *vt;
};

struct Actor {
    char pad0[4];
    struct Script *script;
    char pad8[0x58];
    f32 f60;
};

struct Cfg {
    s32 f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    s32 f18;
    s32 f1C;
    char pad20[0xC];
    void *f2C;
    s32 f30;
    char pad34[4];
    void *f38;
    s32 f3C;
    u8 bufA[0x20];
    u8 bufB[0x20];
    char pad80[8];
};

struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
};

extern M2C_UNK D_003D0950 __attribute__((section(".data")));
extern M2C_UNK D_003D0970 __attribute__((section(".data")));
extern M2C_UNK D_003DE870 __attribute__((section(".data")));
extern M2C_UNK D_003DFBC0 __attribute__((section(".data")));

extern M2C_UNK DebugPrintf(M2C_UNK *);
extern void func_00131188(void *, s32, s32);
extern void func_0014DF80(void *);
extern struct Script *func_0014EB30(s32, void *);
extern void func_0016A5F0(struct Script *);
extern void func_002806A0(struct Script *, struct Cfg *);
extern void func_00151AB0(struct Script *, struct Vec4 *);
extern void func_00151A20(struct Script *, struct Vec4 *);
extern s32 func_00151990(struct Script *, f32 *);
extern f32 func_00305310(void);

void func_003108A0(struct Actor *actor, s32 arg1, void *arg2, s32 arg3) {
    struct Script *script;
    struct Cfg cfg;
    struct Vec4 vec;
    f32 args[4];
    u8 *q;
    s32 j;

    if (arg1 == 0) {
        DebugPrintf(&D_003D0970);
        return;
    }
    func_0014DF80(&actor->pad8);
    script = func_0014EB30(0x790, &actor->pad8);
    if (script != 0) {
        func_0016A5F0(script);
        M2C_FIELD(script, M2C_UNK **, 0x1B0) = &D_003DE870;
    }
    actor->script = script;
    if (actor->script == 0) {
        DebugPrintf(&D_003D0950);
        return;
    }
    func_00131188(&cfg, 0, 0x88);
    cfg.f00 = arg1;
    cfg.f04 = &D_003DFBC0;
    cfg.f08 = &actor->pad8;
    cfg.f0C = &actor->pad8;
    cfg.f10 = &actor->pad8;
    cfg.f14 = arg2;
    cfg.f18 = 1;
    cfg.f1C = arg3;
    cfg.f2C = cfg.bufA;
    cfg.f30 = 8;
    cfg.f38 = cfg.bufB;
    cfg.f3C = 8;
    script = actor->script;
    script->vt->func(script);
    func_002806A0(actor->script, &cfg);
    vec.x = 0.0f;
    vec.y = 0.0f;
    vec.z = 0.0f;
    vec.w = 0.0f;
    func_00151AB0(actor->script, &vec);
    func_00151A20(actor->script, &vec);
    q = (u8 *)args;
    for (j = 0; j < 0x10; j++) {
        q[j] = 0;
    }
    args[0] = 1.0f;
    args[1] = 1.0f;
    args[2] = func_00151990(actor->script, args);
    actor->f60 = func_00305310();
}
