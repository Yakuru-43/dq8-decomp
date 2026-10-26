// range: 0x25E0A0 0x25E0C0
#include "common.h"

extern int func_00100480();
extern int func_0025E0C0();
extern u32 D_0041CBC0[74];   /* 0x128-byte queue registered here */

void func_0025E0A0(void) {
    func_00100480(D_0041CBC0, func_0025E0C0, 0x128, 6);
}
