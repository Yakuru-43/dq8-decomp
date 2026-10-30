// range: 0x37AD80 0x37AE20
#include "common.h"

extern s32 D_003AF2A0[];

char *func_00201CD0(void);
char *func_002D34C0(void);
void func_002D38E0(char *, s32, s32, s32);
void func_00370C00(char *, s32, s32);
void func_0037CE30(s32);
void func_0037D060(s32);

void func_0037AD80(s32 arg0) {
    char *temp_v0;

    temp_v0 = func_002D34C0();
    func_002D38E0(temp_v0, 0x485, 0, -1);
    if (arg0 == 3) {
        func_0037D060(-1);
    }
    func_002D38E0(temp_v0, 0x18700, 0, -1);
    func_0037CE30(0);
    func_00370C00(func_00201CD0(), D_003AF2A0[arg0], 0);
}
