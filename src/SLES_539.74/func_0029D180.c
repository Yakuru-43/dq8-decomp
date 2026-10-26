// range: 0x29D180 0x29D1F0
#include "common.h"

typedef struct Obj0029D180 {
    char pad0[0x3C];
    u8 mode;
    char pad1[3];
    s32 field40;
    s32 field44;
    char pad2[0x444];
    s32 field48C;
    s32 list490[32];
    s32 list510[6];
    char pad3[0x68];
    s32 list590[6];
    s32 list5A8[6];
    s32 list5C0[6];
} Obj0029D180;

extern s32 D_004523E0 __attribute__((section(".data")));
extern s32 func_0029D1F0(void *arg0);

s32 func_0029D180(Obj0029D180 *obj, s32 mode, s32 arg2)
{
    s32 i;

    obj->field48C = -1;
    for (i = 0; i < 32; i++) {
        obj->list490[i] = 0;
    }
    for (i = 0; i < 6; i++) {
        obj->list510[i] = 0;
        obj->list590[i] = 0;
        obj->list5A8[i] = 0;
        obj->list5C0[i] = 0;
    }
    obj->mode = (u8)mode;
    obj->field40 = 0;
    obj->field44 = arg2;
    return func_0029D1F0(&D_004523E0);
}
