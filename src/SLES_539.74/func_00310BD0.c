// range: 0x310BD0 0x310C60
#include "common.h"

struct Obj {
    u8 pad_0[0x60];
    s32 field_60;
    u8 pad_64[4];
    s32 field_68;
    u8 pad_6C[0x15C];
    s32 field_1C8;
};

extern void *func_00168160(void);
extern void *func_0016D5B0(void *, s32);

void func_00310BD0(struct Obj *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;
    s32 var_v1;

    temp_v0 = func_00168160();
    if (temp_v0 == NULL) {
        return;
    }
    temp_v0_2 = func_0016D5B0(temp_v0, arg0->field_60);
    if (temp_v0_2 == NULL) {
        return;
    }
    arg0->field_68 = arg1;
    switch (arg1) {
    case 0:
        var_v1 = *(s32 *)((char *)temp_v0_2 + 0x1C8) & ~1;
        *(s32 *)((char *)temp_v0_2 + 0x1C8) = var_v1;
        break;
    case 1:
        *(s32 *)((char *)temp_v0_2 + 0x1C8) |= 1;
        break;
    }
}
