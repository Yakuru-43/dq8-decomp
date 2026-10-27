// range: 0x1C2570 0x1C25B0
#include "common.h"

M2C_UNK func_0020BFE0(f32, s32);
extern s32 D_003E0664;

s32 func_001C2570(char *arg0) {
    f32 val;

    if (*(s32 *)arg0 == 0) {
        val = (f32)*(s32 *)(arg0 + 4);
    } else {
        val = *(f32 *)(arg0 + 4);
    }
    func_0020BFE0(val, D_003E0664);
    return 1;
}
