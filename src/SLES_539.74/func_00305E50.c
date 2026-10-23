// range: 0x305E50 0x305E90
#include "common.h"

void func_00176010(s32, f32);                         /* extern */

void func_00305E50(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        func_00176010(i, 1.0f);
    }
}
