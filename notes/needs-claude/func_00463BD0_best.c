// range: 0x463BD0 0x463D30
#include "common.h"

void func_181420(void);
s32 func_202530(void);
s32 func_2D34C0(void);
void func_131188(void *, s32, s32);
void func_133CB8(s32, char *);
s32 func_205D30(s32, s32);
s32 func_205250(s32, s32);
void func_36F4D0(s32, char *);
void func_2F4150(char *);
s32 func_1FFC30(s32);
void func_00464420(s32);
void func_2D7120(M2C_UNK *, s32, s32, s32);
void func_37EB00(s32);
void func_2D38E0(M2C_UNK *, s32, s32, s32);
void func_2D4FC0(M2C_UNK *, s32, s32, s32);
extern char D_3E19A0[8];
extern char D_004737C0[] __attribute__((section(".data")));

void func_00463BD0(void) {
    char buf[0x200];
    char tmp[0x60];
    s32 panel;
    M2C_UNK *win;
    char *p;
    s32 count;
    s32 i;

    func_181420();
    panel = func_2D34C0();
    win = (M2C_UNK *)panel;
    func_131188(&D_3E19A0[0], -1, 5);
    buf[0] = 0;
    for (i = 0; i < func_202530(); i++) {
        count = func_205D30(panel, i);
        p = &D_3E19A0[i];
        *p = count;
        if (i != 0) {
            func_133CB8((s32)buf, &D_004737C0[0]);
        }
        func_36F4D0(func_205250(panel, *p), tmp);
        func_2F4150(tmp);
        func_133CB8((s32)buf, tmp);
    }
    D_3E19A0[i] = 4;
    func_133CB8((s32)buf, &D_004737C0[0]);
    func_133CB8((s32)buf, (char *)func_1FFC30(0x130));
    func_00464420((s32)buf);
    func_2D7120(win, 0x2733, 0x10E, 0x50);
    func_37EB00(1);
    func_2D38E0(win, 0x1797, 1, -1);
    func_2D4FC0(win, 0x1798, 0xFC, 0x66);
    func_2D7120(win, 0x1797, 0x10E, 0xF6);
}
