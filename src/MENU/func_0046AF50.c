// range: 0x46AF50 0x46B000
#include "common.h"

struct SubStruct {
    u8 pad0[0xA];
    s16 field_A;
    u8 pad_C[0x6];
    s16 field_12;
};

struct MainStruct {
    u8 pad0[0x18];
    struct SubStruct *sub;
    u8 pad_1C[0x4];
    void *field_20;
};

extern s32 func_2D38E0(void *, u32, s32, s32);
extern void func_370590(void *, s32);
extern void func_37AB80(s32, s16, void *);
extern void func_37AE60(s32 *, s32);
extern void func_37C720(s16);

s32 func_0046AF50(struct MainStruct *arg0, void *arg1) {
    s32 sp3C;

    func_37AE60(&sp3C, 0);
    arg0->sub->field_A = (s16)(sp3C - 1);
    func_370590(arg0->field_20, 0x28);
    func_37C720(arg0->sub->field_12);
    func_2D38E0(arg1, 0x18703, 1, -1);
    func_2D38E0(arg1, 0x186E8, 1, -1);
    func_37AB80(3, arg0->sub->field_12, 0);
    return 1;
}
