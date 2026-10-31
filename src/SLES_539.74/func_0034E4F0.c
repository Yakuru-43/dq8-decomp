// range: 0x34E4F0 0x34E580
#include "common.h"

s32 func_0015F490(void);
void func_001419A0(s32, s32, f32);
void func_002E4DE0(void *, s16);
void func_00221F50(void *);

typedef struct Obj {
    char pad000[0x17E];
    s16 field_17E;
    char pad180[0x1668 - 0x180];
    s32 field_1668;
    char pad166C[0x1F18 - 0x166C];
    s32 field_1F18;
} Obj;

void func_0034E4F0(Obj *obj, s32 flag) {
    s32 work;

    work = func_0015F490();
    func_001419A0(work, obj->field_1668, 1.0f);
    if (flag != 0) {
        func_002E4DE0(obj, 0x28);
        obj->field_1F18 = obj->field_17E - 12;
    } else {
        func_002E4DE0(obj, 0x17C);
        obj->field_1F18 = obj->field_17E - 12;
    }
    func_00221F50(obj);
}
