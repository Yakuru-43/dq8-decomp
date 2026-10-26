// range: 0x21B8C0 0x21B920
#include "common.h"

void func_0020D8E0(void);                            /* extern */
M2C_UNK func_00176500(M2C_UNK);                      /* extern */
extern u16 D_003E0980;
extern u16 D_003E0984;
extern s32 D_00415D40[4];

void func_0021B8C0(void) {
    s32 i;

    func_0020D8E0();
    D_003E0980 = 0;
    D_003E0984 = 0;
    for (i = 0; i < 4; i++) {
        D_00415D40[i] = 0;
    }
    func_00176500(8);
}
