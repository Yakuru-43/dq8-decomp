// range: 0x468F10 0x469150
#include "common.h"

typedef struct MenuItem {
    /* 0x0 */ s16 f0;
    /* 0x2 */ s16 f2;
    /* 0x4 */ s16 f4;
    /* 0x6 */ s16 f6;
} MenuItem;

void *func_2D34C0(void);                                    /* extern */
s32 func_00469950(void);                                    /* extern */
s32 func_181420(void);                                      /* extern */
s32 func_203740(s32, u32, s32, MenuItem *, s32);             /* extern */
s32 func_1FFC30(s32);                                       /* extern */
void func_2D58C0(void *, s32, s32, s32);                     /* extern */
s32 func_2D57D0(void *, s32, s32, s32);                      /* extern */
void func_2D70A0(void *, s32, s32);                          /* extern */
void func_2D6B20(void *, s32, s32, s32, s32);                /* extern */
s32 func_00469C20(s32, s32, s32);                            /* extern */
void func_2D4E40(void *, s32, s32, MenuItem);                /* extern */
void func_2D4E00(void *, s32, s32, s32, s32);                /* extern */
void func_2D5C20(void *, s32, s32, s32, s32, s32);           /* extern */
extern MenuItem D_00479CA0[] __attribute__((section(".data")));
extern s32 D_003E1A34;

void func_00468F10(s32 arg0) {
    void *panel;
    u32 handle;
    s32 i;
    s32 cell;
    MenuItem *e;
    s32 rem;
    s32 quot;
    s32 count;

    panel = func_2D34C0();
    if (panel == 0) {
        return;
    }
    func_00469950();
    handle = func_181420();
    D_003E1A34 = func_203740(handle, handle, arg0, D_00479CA0, 0xD);
    func_2D58C0(panel, 0x186E1, func_1FFC30(arg0 + 0x33), 0);
    count = func_2D57D0(panel, 0x186E1, 0, 0);
    func_2D70A0(panel, 0x186E1, (0x9A - count) >> 1);
    func_2D6B20(panel, 0x594, 0x596, arg0 * 46 - 6, -4);
    i = 0;
    do {
        cell = func_00469C20(i, 0, 0);
        e = &D_00479CA0[i];
        func_2D4E40(panel, 0, cell, *e);
        rem = i % 4;
        quot = i / 4;
        func_2D4E00(panel, 0x588, i, rem * 0x30, quot * 0x30);
        if (0 < e->f0) {
            func_2D5C20(panel, 0x587, 1, -1, cell, 1);
        } else {
            func_2D5C20(panel, 0x587, 1, 1, cell, 1);
        }
        if (e->f4 != 0) {
            func_2D5C20(panel, 0x483, 1, -1, cell, 1);
        } else {
            func_2D5C20(panel, 0x483, 1, 1, cell, 1);
        }
        i++;
    } while (i < 12);
}
