// range: 0x18FC30 0x18FCE0
#include "common.h"

void func_00131188(char *, s32, s32);
s32 func_001667C0(void);
s32 func_0018FCE0(char *);
void func_0014E030(char *);
s32 func_0014E920(s32, char *);
extern s16 D_003E053C;
extern s32 D_003E0540;
extern s32 D_003E0554;
extern s32 D_003E0558;
extern s32 D_003E055C;
extern s16 D_003E0560;
extern char *D_003E0564;

s32 func_0018FC30(void) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_s1;

    D_003E0558 = 0;
    D_003E0554 = 0;
    temp_v0 = func_001667C0();
    D_003E053C = temp_v0;
    temp_v0_2 = func_0014E920(temp_v0 * 0x1C, D_003E0564);
    D_003E0554 = temp_v0_2;
    var_s1 = 0;
    D_003E0540 = temp_v0_2;
    while (var_s1 < temp_v0) {
        func_00131188((char *)D_003E0554 + (var_s1 * 0x1C), 0, 0x1C);
        var_s1++;
    }
    func_0014E030(D_003E0564);
    D_003E055C = func_0018FCE0(D_003E0564);
    D_003E0560 = 0;
    return 1;
}
