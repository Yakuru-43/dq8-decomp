// range: 0x1C1660 0x1C16A0
#include "common.h"

M2C_UNK func_001AC780(void *, s32, f32);
extern M2C_UNK D_00411ED0 __attribute__((section(".data")));

void func_001C1660(char *arg0) {
    s32 a1;
    f32 a2;

    if (*(s32 *)arg0 == 1) {
        a1 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a1 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 0) {
        a2 = (f32)*(s32 *)(arg0 + 0xC);
    } else {
        a2 = *(f32 *)(arg0 + 0xC);
    }
    func_001AC780(&D_00411ED0, a1, a2);
}
