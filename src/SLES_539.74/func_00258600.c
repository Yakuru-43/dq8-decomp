// range: 0x258600 0x258630
#include "common.h"

extern int func_00131188();
extern u8 D_0041C950 __attribute__((section(".data")));
extern u8 D_0041C930[] __attribute__((section(".data")));
extern s32 D_003E0C1C;
extern s32 D_003E0C20;
extern s32 D_003E0C28;
extern s32 D_003E0C2C;

void func_00258600(void) {
    D_0041C950 = 0;
    D_003E0C1C = 0;
    D_003E0C20 = 0;
    D_003E0C28 = 0;
    D_003E0C2C = 0;
    func_00131188(D_0041C930, 0, 0x20);
}
