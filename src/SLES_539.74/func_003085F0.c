// range: 0x3085F0 0x3086E0
// auto: hand, verified byte-exact
#include "common.h"

extern void func_00131188(void *, s32, s32);
extern void func_00206230(void *);
extern void func_0024BAD0(void *);
extern void func_002B21F0(void *);
extern void func_00305300(void *);

struct StatObj {
    char pad0[0x10];
    s32 field10;
    s32 field14;
    s32 field18;
    s32 field1C;
    s32 field20;
    s32 field24;
    s32 field28;
    char pad2C[0x24];
    u32 bits[0x40];
    s16 values[0x80];
    char pad250[0x220];
    char region470[0x580];
    char sub9F0[0xD10];
    char sub1700[0x4190];
    char sub5890[0x140];
    char sub59D0[0x270];
    char sub5C40[0x60];
};

void func_003085F0(struct StatObj *obj) {
    s32 i;
    u32 sub;

    func_00131188(obj, 0, 0x5CA0);
    for (i = 0; i < 0x40; i++) {
        obj->bits[i] = 0;
    }
    for (i = 0; i < 0x80; i++) {
        obj->values[i] = 0;
    }
    sub = (u32)&obj->field10;
    if (sub != 0) {
        func_00131188((void *)sub, 0, 0x30);
        obj->field20 = 5;
        obj->field24 = 5;
        obj->field28 = 5;
        obj->field14 = 0;
        obj->field18 = 1;
    }
    func_00131188(obj->region470, 0, 0x580);
    func_00206230(obj->sub9F0);
    func_00305300(obj->sub1700);
    func_0024BAD0(obj->sub59D0);
    func_002B21F0(obj->sub5890);
    func_00131188(obj->sub5C40, 0, 0x60);
}
