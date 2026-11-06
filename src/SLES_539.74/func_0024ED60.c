// range: 0x24ED60 0x24EE00
#include "common.h"

extern int func_00252348();
extern int func_00252350();
extern int func_00252400();
extern s32 D_003DFD70;
extern u8 D_0041B130[];

void func_0024ED60(void) {
    s32 i;

    func_00252348(0);
    D_003DFD70 = func_00252350(5);
    func_00252400(0, 0x8F, 0x880);
    func_00252400(3, 0x83, 0x105, 0, 0);
    func_00252400(3, 0x82, 0);
    func_00252400(3, 0x80, 0x7F, 0x7F);
    for (i = 0; i < 0x27; i++) {
        D_0041B130[i] = 0;
    }
}
