// range: 0x36E970 0x36E9A0
// auto: m2c draft, verified byte-exact
#include "common.h"

typedef struct {
    char pad0[0x4];
    s16 unk4;
    char pad6[0x55F];
    s8 unk565;
    char pad566[0x12];
    s32 unk578;
    char pad57C[0xC];
    s16 unk588;
    s16 unk58A;
} S_arg0;

void func_0036E970(S_arg0 *arg0) {
    arg0->unk578 = 0;
    arg0->unk588 = 0;
    arg0->unk565 = 0;
    arg0->unk58A = 0;
    if (arg0->unk4 == 1) {
        arg0->unk58A = 1;
    }
}
