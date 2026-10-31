// range: 0x27D5A0 0x27D600
#include "common.h"

M2C_UNK func_0027E4E0();
M2C_UNK func_0027D670();

void func_0027D5A0(void *a0, s32 a1, void *a2) {
    u8 bufA[0x10];
    u8 bufB[0x10];

    func_0027E4E0(bufA, a1, a0);
    func_0027E4E0(bufB, a2, a0);
    func_0027D670(bufA, bufB);
}
