// range: 0x305740 0x305800
#include "common.h"

s32 func_00168160();                                /* extern */
s32 func_00167A80();                                /* extern */
void func_0020B4B0(char *, s32);                     /* extern */
void func_001339E0(char *, char *, char *);          /* extern */
void func_003721C0(s32, s32, f32);                   /* extern */
void func_00371840(s32, s32);                        /* extern */
void func_00371C10(s32, s32, char *, s32);           /* extern */
extern s32 func_003763D0(void);                      /* extern */
extern s32 D_003E114C;
extern char D_003D0160[];
extern f32 D_003D0100[];

void func_00305740(s32 arg0, s32 arg1) {
    char bufD0[0x80];
    char buf50[0x80];
    s32 unk;
    s32 obj;

    unk = func_00168160();
    obj = func_00167A80();
    D_003E114C = 0;
    if (unk == 0) {
        return;
    }
    func_0020B4B0(buf50, arg0);
    func_001339E0(bufD0, D_003D0160, buf50);
    func_003721C0(obj, 2, D_003D0100[func_003763D0()]);
    func_00371840(obj, 2);
    func_00371C10(obj, 2, bufD0, arg1);
}
