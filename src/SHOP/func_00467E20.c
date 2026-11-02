// range: 0x467E20 0x467F30
#include "common.h"

M2C_UNK func_00461690(void *, s32, s32, s32);                       /* extern */
M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                               /* extern */
M2C_UNK func_3768A0(void *);                                         /* extern */
M2C_UNK func_3791B0(void *);                                         /* extern */
M2C_UNK func_3794B0(void);                                           /* extern */
M2C_UNK func_3795F0(s32);                                            /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, void (*)(void), s32);    /* extern */
s32 func_1814D0(void);                                               /* extern */
s32 func_308030(s32);                                                /* extern */
void func_004680F0(void);

extern M2C_UNK D_00473890 __attribute__((section(".data")));

typedef struct {
    u128 q[22];
} ShopWindow;

s32 func_00467E20(void *arg0, s32 arg1) {
    ShopWindow buf;
    s32 r;

    if (func_3791B0(arg0) != 1) { return 1; }
    r = func_3794B0();
    func_2D38E0(arg1, 0x17A3, 0, -1);
    func_3768A0(&buf);
    if (r == 0) {
        func_3766A0(&buf, 0x32C9, 1);
        func_00461690(&buf, 0, func_308030(func_1814D0()), -1);
        func_379760(&buf, &D_00473890, 0, 0, 1);
    } else if (r == 1) {
        func_3766A0(&buf, 0x3323, 1);
        func_379760(&buf, 0, 1, func_004680F0, 1);
        func_3795F0(0xFFFF);
    }
    return 1;
}
