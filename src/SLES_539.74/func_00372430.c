// range: 0x372430 0x3724B0
#include "common.h"

void func_001340C0(char *, char *);
s32 func_0025AB80(s32);
void func_0025B640(s32, s32 *);
s32 func_0025B760(s32);

void func_00372430(char *arg0, char *arg1) {
    func_0025B640(*(s16 *)(arg0 + 2), (s32 *)(arg1 + 0x54));
    if (*(s32 *)(arg1 + 0x54) <= 0) {
        *(s8 *)arg1 = 0;
    } else {
        *(s8 *)arg1 = 1;
    }
    *(s32 *)(arg1 + 4) = *(s32 *)(arg0 + 8);
    *(f32 *)(arg1 + 8) = *(f32 *)(arg0 + 0xC);
    *(s32 *)(arg1 + 0xC) = func_0025B760(*(s16 *)(arg0 + 2));
    *(s32 *)(arg1 + 0x10) = func_0025AB80(*(s16 *)(arg0 + 2));
    func_001340C0(arg1 + 0x14, arg0 + 0x24);
}
