// range: 0x311780 0x311800
#include "common.h"

struct Owner {
    char pad0[0x64];
    s16 field64;
    char pad66[2];
    s32 *slots[6];
};

extern s32 func_0015F450(void);
extern void func_0015A320(s32, s32 *);
extern void func_00159630(s32, s16);

void func_00311780(struct Owner *o) {
    s32 mgr;
    s32 i;

    mgr = func_0015F450();
    for (i = 0; i < 6; i++) {
        if (o->slots[i]) {
            func_0015A320(mgr, o->slots[i]);
            o->slots[i] = 0;
        }
    }
    func_00159630(mgr, o->field64);
}
