// range: 0x30D4F0 0x30D580
#include "common.h"

struct Elem {
    f32 unk0;
    s8 unk4;
};

void *func_0030D580(void *arg0, void *arg1);      /* extern */
M2C_UNK func_00356920(void *, s32);               /* extern */
M2C_UNK func_003568E0(s32, void *, s32);           /* extern */

void func_0030D4F0(s32 arg0, s32 *arg1) {
    struct Elem work;

    if (*arg1 <= 0) {
        func_003568E0(arg0, 0, -1);
        return;
    }
    *arg1 = *arg1 - 1;
    func_0030D580(&work, (void *)((char *)arg1 + *arg1 * 8 + 4));
    func_00356920((void *)((char *)arg1 + *arg1 * 8 + 4), 0);
    func_0030D580((void *)arg0, &work);
}
