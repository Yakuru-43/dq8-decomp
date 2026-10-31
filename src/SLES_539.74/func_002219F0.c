// range: 0x2219F0 0x221AB0
#include "common.h"

M2C_UNK func_00221B00(void *, M2C_UNK);              /* extern */
M2C_UNK func_00221AC0(void *);                       /* extern */
M2C_UNK func_002218D0(void *);                       /* extern */
M2C_UNK func_002223C0(void *, M2C_UNK);              /* extern */
M2C_UNK func_002E5710(void *, s32, s32);             /* extern */
M2C_UNK func_00221AB0(void *, s8);                   /* extern */
M2C_UNK func_002E67B0(void *, s32, s8);              /* extern */
M2C_UNK func_002F6330(void *, s8);                   /* extern */
M2C_UNK func_002FFAB0(void *, s32, s32, s32, s32);   /* extern */

void func_002219F0(void *arg0) {
    s32 i;

    func_00221B00(arg0, 0);
    func_00221AC0(arg0);
    func_002218D0(arg0);
    func_002223C0(arg0, 1);
    func_002E5710(arg0, 0, 0);
    func_00221AB0(arg0, 1);
    for (i = 0; i < 20; i = i + 1) {
        func_002E67B0(arg0, i, -1);
    }
    func_002F6330(arg0, 0);
    func_002FFAB0((char *)arg0 + 0xC0, -1, -1, -1, -1);
    M2C_FIELD(arg0, s16 *, 0x1F34) = -1;
}
