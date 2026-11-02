// range: 0x464420 0x464530
#include "common.h"

void *func_2D34C0(void);
void func_37ECA0(s32, s32);
void func_37ECF0(s32, s32, s32, s32, s32);
void func_2D7120(void *, s32, s32, s32);
s32 func_1FFC30(s32);
void func_2D58C0(void *, s32, s32, s32);
void *func_2D5410(void *, s32);
s32 func_2E6770(void *, s32);
void func_2E6880(void *, s32, s32, s32);
extern s32 func_202530(void);
void func_2D38E0(void *, s32, s32, s32);
void func_00464530(void *, s32);

void func_00464420(s32 arg0) {
    void *panel;
    s32 i;
    void *item;
    s32 half;

    panel = func_2D34C0();
    func_37ECA0(0x2733, arg0);
    func_37ECF0(0x2733, 0, 0xFC, 0x116, 0);
    func_2D7120(panel, 0x2733, 0x10E, 0x50);
    func_2D58C0(panel, 0x2736, func_1FFC30(0xA0), 0);
    for (i = 0; i < func_202530() + 1; i++) {
        item = func_2D5410(panel, 0x2737);
        half = func_2E6770(item, i);
        func_2E6880(item, i, 0x168 - (half >> 1), i * 24 + 100);
    }
    func_2D38E0(panel, 0x17A3, 1, -1);
    func_00464530(0, 1);
}
