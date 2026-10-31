// range: 0x001C7F60 0x001C7FF0
#include "common.h"

extern s32 D_00412D70[];
void func_001D1E60(void *arg0, s32 arg1);

s32 func_001C7F60(char *arg0) {
    s32 a2;
    s32 a1;
    s32 *a0;

    if (*(s32 *)arg0 == 1) {
        a2 = (s32)*(f32 *)(arg0 + 4);
    } else {
        a2 = *(s32 *)(arg0 + 4);
    }
    if (*(s32 *)(arg0 + 8) == 1) {
        a1 = (s32)*(f32 *)(arg0 + 0xC);
    } else {
        a1 = *(s32 *)(arg0 + 0xC);
    }
    if (a2 < 0 || a2 >= 4) {
        a0 = 0;
    } else {
        a0 = &D_00412D70[a2 * 32];
    }
    if (a0 == 0) {
        return 0;
    }
    func_001D1E60(a0, a1);
    return 1;
}
