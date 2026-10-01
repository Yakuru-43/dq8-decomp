// range: 0x194990 0x1949E0
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00256AA0();                              /* extern */
void *func_00348D20(s8);                            /* extern */
extern s16 D_0040FFD6 __attribute__((section(".data")));

s32 func_00194990(void) {
    void *temp_v0;
    void *temp_v0_2;

    temp_v0_2 = func_00256AA0();
    if (temp_v0_2 != NULL) {
        temp_v0 = func_00348D20(M2C_FIELD(temp_v0_2, s8 *, 8));
        if (temp_v0 != NULL) {
            return M2C_FIELD(temp_v0, s32 *, 0x18);
        }
    }
    return (s32) D_0040FFD6;
}
