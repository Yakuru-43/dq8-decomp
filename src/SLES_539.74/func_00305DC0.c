// range: 0x305DC0 0x305E40
#include "common.h"

u32 func_001813D0(void);                              /* extern */
extern f32 *D_003DFF88;
extern f32 *D_003DFF8C;

f32 func_00305DC0(s32 arg0) {
    u32 p;
    f32 val;

    p = func_001813D0();
    if (p == 0) {
        return 1.0f;
    }
    if (arg0 == 0) {
        val = D_003DFF88[*(s32 *)(p + 0x10)];
    }
    if (arg0 == 1) {
        val = D_003DFF8C[*(s32 *)(p + 0x14)];
    }
    return val;
}
