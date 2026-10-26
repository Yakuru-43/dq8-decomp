// range: 0x311470 0x3114F0
#include "common.h"

struct Owner {
    s32 field0;
    char pad4[0x60];
    s32 field64;
    char pad68[4];
    s32 field6C;
};

extern s32 func_00168160(void);
extern s32 func_0015F450(void);
extern void func_0016A430(s32, s32);
extern void func_00159630(s32, s32);

void func_00311470(struct Owner *o) {
    s32 a;
    s32 b;

    a = func_00168160();
    b = func_0015F450();
    func_0016A430(a, o->field64);
    func_00159630(b, o->field6C);
    func_00159630(b, o->field0 + 0x187);
    func_0016A430(a, o->field0 + 0xB9);
}
