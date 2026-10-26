// range: 0x221F50 0x221F90
#include "common.h"

extern void func_00222000(void *arg0, s32 arg1);
extern void func_00221F90(void *arg0, s32 arg1);

struct Obj {
    u8 pad_0[0x11E8];
    u8 field_11E8;
};

void func_00221F50(struct Obj *obj) {
    func_00222000(obj, obj->field_11E8);
    func_00221F90(obj, obj->field_11E8);
}
