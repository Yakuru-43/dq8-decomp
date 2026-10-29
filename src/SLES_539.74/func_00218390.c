// range: 0x218390 0x218410
#include "common.h"

char * func_00168160(void);
void func_003056D0(void);
void func_00305740(s32, s32);
extern u8 D_003E0990;
extern s16 D_003E0994;
extern s16 D_003E0998;

s32 func_00218390(void) {
    func_00168160();
    if (D_003E0990 != 0) {
        if (0 < D_003E0998) {
            D_003E0998 -= 1;
            if (D_003E0998 == 0) {
                func_00305740(0x3F, 0);
                func_003056D0();
            }
        } else {
            if (D_003E0994 < 0xBC) {
                D_003E0994 += 1;
            }
        }
    }
    return 0;
}
