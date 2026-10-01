// range: 0x18DEA0 0x18DEE0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_0014EA80(s32, s32);                        /* extern */
s16 func_001667C0();                                /* extern */
extern s16 D_003E054C;
extern s32 D_003E0550;
extern s32 D_003E056C;

s32 func_0018DEA0(void) {
    D_003E054C = func_001667C0();
    D_003E0550 = func_0014EA80(D_003E054C * 0xC, D_003E056C);
    return 1;
}
