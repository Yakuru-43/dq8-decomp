// range: 0x1979F0 0x197A80
#include "common.h"

extern "C" {
extern s8 D_003E05BC;
extern s8 D_0040FFA1 __attribute__((section(".data")));
extern s8 D_0040FFF4 __attribute__((section(".data")));
extern s8 D_00410044 __attribute__((section(".data")));
extern s32 func_00263850(void);

s32 func_001979F0(void) {
    s32 count;

    if (D_003E05BC == 0) {
        return 0;
    }

    count = 0;
    if (D_0040FFA1 != 0) {
        count++;
    }
    if (func_00263850() != 0) {
        count++;
    }
    if ((D_00410044 == 1) != false) {
        count++;
    }
    if ((0 < D_0040FFF4) != false) {
        count++;
    }
    return count;
}
}
