// range: 0x4697E0 0x469890
#include "common.h"

struct Struct18 {
    /* 0x00 */ u8 pad0[0xA];
    /* 0x0A */ s16 field_0A;
    /* 0x0C */ u8 pad1[0x6];
    /* 0x12 */ s16 field_12;
};

struct Struct00 {
    /* 0x00 */ u8 pad0[0x18];
    /* 0x18 */ struct Struct18 *field_18;
};

extern s32 func_004699A0(s16, s32);
extern s32 func_202530(void);
extern void func_2D38E0(void *, s32, s32, s32);
extern void func_37CEE0(s32);

s32 func_004697E0(struct Struct00 *arg0, void *arg1) {
    func_2D38E0(arg1, 0x585, 0, -1);
    func_2D38E0(arg1, 0x49C, 0, -1);
    func_2D38E0(arg1, 0x485, 0, -1);
    func_2D38E0(arg1, 0x4A2, 0, -1);
    func_004699A0(arg0->field_18->field_12, 0);
    func_37CEE0(1);
    arg0->field_18->field_0A = (s16)(func_202530() - 1);
    return 1;
}
