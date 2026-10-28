// range: 0x145D70 0x145DC0
#include "common.h"

extern void func_0015B580(s32);
extern void func_0015B3F0(s32, s32, s32);

typedef struct {
    u8 pad_0[0x170];
    s32 field_170;
    s32 field_174;
} SubObj;

typedef struct {
    u8 pad_0[0x270];
    SubObj *sub;
    u8 pad_1[0x3B90 - 0x274];
    s32 field_3B90;
} MainObj;

void func_00145D70(MainObj *arg0) {
    s32 a0;
    SubObj *v0;

    a0 = arg0->field_3B90;
    if (a0 == 0) {
        return;
    }
    func_0015B580(a0);
    a0 = arg0->field_3B90;
    if (a0 == 0) {
        return;
    }
    v0 = arg0->sub;
    func_0015B3F0(a0, v0->field_170, v0->field_174);
}
