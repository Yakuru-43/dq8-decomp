// range: 0x46D4E0 0x46D590
#include "common.h"

s32 func_2D34C0();                                      /* extern */
M2C_UNK func_2D7560(s32, M2C_UNK, void *, void *);       /* extern */
M2C_UNK func_2D4F30(s32, M2C_UNK, void *, void *);       /* extern */
M2C_UNK func_2D6110(s32, M2C_UNK, s32, M2C_UNK, M2C_UNK); /* extern */

void func_0046D4E0(void) {
    s32 local_2C;
    s32 local_28;
    s32 local_24;
    s32 local_20;
    s32 handle;

    handle = func_2D34C0();
    if (handle == 0) {
        return;
    }
    func_2D7560(handle, 0x2733, &local_2C, &local_28);
    func_2D4F30(handle, 0x2734, &local_24, &local_20);
    func_2D6110(handle, 0x2744, 0, local_2C - 8, local_28 + local_20 - 0x4A);
    func_2D6110(handle, 0x2744, 1, local_2C + local_24 - 0x4A,
                local_28 + local_20 - 0x4A);
}
