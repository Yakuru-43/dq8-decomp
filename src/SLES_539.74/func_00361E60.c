// range: 0x361E60 0x361EE0
#include "common.h"

void func_00141CE0(char *);
s32 func_0015F490(void);
void func_00141D10(s32, s32);
void func_00142700(s32, s32);
s32 func_00361EE0(void);
extern s32 D_003E1408;
extern s32 D_003E140C;
extern s32 D_003E1410;
extern s16 D_003E1414;

void func_00361E60(void) {
    s32 temp_s0;
    s32 temp_s1;

    D_003E1410 = 0;
    D_003E1414 = 0;
    temp_s1 = func_0015F490();
    while (D_003E1408 != 0) {
        func_00142700(temp_s1, 1);
        temp_s0 = func_00361EE0();
        func_00141D10(temp_s1, 1);
        if (temp_s0 == 0) {
            continue;
        }
        break;
    }
    func_00141CE0((char *)temp_s1);
    D_003E140C = 1;
}
