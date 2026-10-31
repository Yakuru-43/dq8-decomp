// range: 0x00352060 0x003520F0
#include "common.h"

void func_002637C0(s32);
void func_0017A9E0(void *);
void func_0020BF90(void *, s32);
void func_0017AD90(s32);
s32 func_003071E0(void);
extern u8 D_003E13B8;
extern u8 D_003E13BC;
extern s32 D_003E13C0;
extern s16 D_003E13C4;

void func_00352060(void *arg0, s32 arg1) {
    D_003E13BC = 0;
    D_003E13B8 = arg1;
    D_003E13C0 = 0;
    if (arg0 == 0) {
        return;
    }
    func_002637C0(0);
    func_0017A9E0(arg0);
    func_0020BF90(arg0, 0x14);
    if (arg1 != 0) {
        D_003E13C4 = 0x18;
    } else {
        D_003E13C4 = func_003071E0();
    }
    func_0017AD90(0x1E);
}
