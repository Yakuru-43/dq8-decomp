// range: 0x4666D0 0x466770
#include "common.h"

s32 func_263CF0();                                        /* extern */
void func_2F6630(s32, s32);                               /* extern */
s32 func_1814D0();                                        /* extern */
M2C_UNK func_308030(s32);                                 /* extern */
s32 func_1339E0(void *, char *, ...);                     /* extern */
void func_2E1F40(void *, s32);                            /* extern */
void func_0045FDD0(s32, s32);                             /* extern */
void func_00466780(s32, s32);                             /* extern */
void func_00466770(s32, void *, s32);                     /* extern */

extern char D_00473988[] __attribute__((section(".data")));

typedef struct {
    u128 pad0;
    char pad10[240];
} WindowText;

void func_004666D0(void) {
    s32 obj;
    WindowText buf;

    func_2F6630(func_263CF0(), 0xB);
    obj = func_263CF0();
    *(s32 *)(obj + 0xF8) = 0x11;
    func_0045FDD0(obj, 0);
    func_1339E0(&buf, D_00473988, func_308030(func_1814D0()));
    func_2E1F40(&buf, 0xFD19);
    func_00466780(obj, -1);
    func_00466770(obj, &buf, 1);
}
