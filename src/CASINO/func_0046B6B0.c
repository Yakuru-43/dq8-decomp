// range: 0x46B6B0 0x46B800
#include "common.h"

extern char *func_0046B840(char *);
extern char *func_0046B820(char *);
extern void func_004681D0(char *);
extern char *func_0046B800(char *);
extern void func_131188(char *, s32, s32);
extern void func_283F10(char *);

extern void *D_3DEA10[];
extern void *D_3DE8D0[];
extern char D_3DEF20[];
extern char D_3DEF00[];
extern char D_3DEEE0[];
extern char D_3DEEC0[];
extern char D_3DEEA0[];

char *func_0046B6B0(char *self) {
    char *p;

    func_0046B840(self);
    *(void **)(self + 0x1B0) = D_3DEA10;
    p = self + 0x228;
    do {
        func_0046B820(p);
        p += 8;
    } while (p < self + 0x248);
    p = self + 0x248;
    do {
        func_0046B820(p);
        p += 8;
    } while (p < self + 0x268);
    func_004681D0(self + 0x270);
    func_0046B800(self + 0x430);
    *(void **)(self + 0x1B0) = D_3DE8D0;
    func_131188(self + 0x4F0, 0, 0x2C);
    *(s32 *)(self + 0x4F0) = -1;
    *(s32 *)(self + 0x4FC) = -1;
    *(s32 *)(self + 0x500) = -1;
    *(s32 *)(self + 0x4F8) = 1;
    *(s32 *)(self + 0x504) = 1;
    *(f32 *)(self + 0x508) = 1.0f;
    *(s32 *)(self + 0x50C) = 0;
    *(s32 *)(self + 0x510) = -1;
    *(s32 *)(self + 0x514) = 0;
    *(s32 *)(self + 0x518) = 0;
    *(s32 *)(self + 0x548) = 0;
    *(s32 *)(self + 0x54C) = 0;
    *(s32 *)(self + 0x550) = 0;
    func_283F10(self + 0x568);
    *(char **)(self + 0x570) = D_3DEF20;
    *(s32 *)(self + 0x574) = 0;
    *(char **)(self + 0x570) = D_3DEF00;
    *(char **)(self + 0x578) = D_3DEF20;
    *(s32 *)(self + 0x57C) = 0;
    *(char **)(self + 0x578) = D_3DEEE0;
    *(char **)(self + 0x580) = D_3DEF20;
    *(s32 *)(self + 0x584) = 0;
    *(char **)(self + 0x580) = D_3DEEC0;
    *(char **)(self + 0x588) = D_3DEF20;
    *(s32 *)(self + 0x58C) = 0;
    *(char **)(self + 0x588) = D_3DEEA0;
    return self;
}
