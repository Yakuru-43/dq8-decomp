// range: 0x305950 0x305A40
#include "common.h"

void func_0020BA80(char *, char *);                   /* extern */
void func_0020C3E0(char *);                           /* extern */
s32 func_00168160();                                  /* extern */
s32 func_00167A80();                                  /* extern */
void func_0020B4B0(char *, s32);                      /* extern */
void func_001339E0(char *, char *, char *);           /* extern */
void func_003721C0(s32, s32, f32);                    /* extern */
void func_00371840(s32, s32);                         /* extern */
void func_00371C10(s32, s32, char *, s32);            /* extern */
s32 func_003763D0(void);                              /* extern */
void func_00371A60(s32, s32, s32, f32);               /* extern */
extern s8 D_003E1140;
extern s32 D_003E114C;
extern char D_003D0160[];
extern f32 D_003D0100[];
extern char D_00450EB0[];

void func_00305950(char *arg0) {
    char bufD0[0x80];
    char buf50[0x80];
    s32 unk;
    s32 obj;

    D_003E1140 = 1;
    func_0020BA80(arg0, D_00450EB0);
    func_0020C3E0(arg0);
    unk = func_00168160();
    obj = func_00167A80();
    D_003E114C = 0;
    if (unk != 0) {
        func_0020B4B0(buf50, 0x40);
        func_001339E0(bufD0, D_003D0160, buf50);
        func_003721C0(obj, 2, D_003D0100[func_003763D0()]);
        func_00371840(obj, 2);
        func_00371C10(obj, 2, bufD0, 0);
    }
    func_00371A60(func_00167A80(), 2, -1, 1.0f);
}
