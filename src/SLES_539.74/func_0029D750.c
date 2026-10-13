// range: 0x29D750 0x29D790
#include "common.h"

typedef struct Obj0029D750 {
    char pad[0x490];
    s32 slots[1];
} Obj0029D750;

extern s32 func_00298380(Obj0029D750 *obj, s32 key);

void func_0029D750(Obj0029D750 *obj, s32 key)
{
    s32 index;

    if (key == 0) {
        return;
    }
    index = func_00298380(obj, key);
    if (index < 0) {
        return;
    }
    obj->slots[index] = 0;
}
