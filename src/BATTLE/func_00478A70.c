// range: 0x478A70 0x478B70
#include "common.h"

extern char *func_16D5B0(void *, s32);
extern char *func_288AB0(char *);
extern s32 func_133F78(s32, char *);
extern void func_0046EBA0(void *);
extern f32 func_004751B0(char *);
extern void func_00478B70(void *);
extern void *D_003E1B8C __attribute__((section(".sdata")));

typedef struct {
    char pad0[0x4];
    s32 field_4;
    char pad8[0xB0];
    s32 field_B8;
    char padBC[0x38];
    f32 field_F4;
    char padF8[0x28];
    s32 field_120;
} S_actor;

s32 func_00478A70(void *arg0, S_actor *actor) {
    char *r;
    char *h;

    r = func_16D5B0(arg0, actor->field_4);
    if (r == 0) {
        func_0046EBA0(actor);
        return 1;
    }
    if (actor->field_B8 == 0) {
        h = func_288AB0(r);
        if (func_133F78(actor->field_120, h) == 0) {
            actor->field_B8 = actor->field_B8 + 1;
        }
    }
    if (actor->field_B8 == 1) {
        if (actor->field_F4 < func_004751B0(r)) {
            func_00478B70(D_003E1B8C);
            func_0046EBA0(actor);
            return 0;
        }
        h = func_288AB0(r);
        if (func_133F78(actor->field_120, h) != 0) {
            func_0046EBA0(actor);
            return 0;
        }
    }
    return 0;
}
