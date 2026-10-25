// range: 0x30CB70 0x30CBC0
#include "common.h"

s32 func_00296F80(s32);                       /* extern */
M2C_UNK func_00356910(s32, s32);              /* extern */

void func_0030CB70(s32 arg0, s32 arg1) {
    s32 id = M2C_FIELD(M2C_FIELD(arg1, s32 *, 0x140), s32 *, 0x1C);

    if (id == 0) {
        func_00356910(arg0, 0);
        return;
    }
    func_00356910(arg0, func_00296F80(id));
}
