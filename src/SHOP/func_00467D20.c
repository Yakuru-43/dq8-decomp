// range: 0x467D20 0x467E20
#include "common.h"

M2C_UNK func_00461690(void *, s32, s32, s32);             /* extern */
M2C_UNK func_376690(void *, s32);                          /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                     /* extern */
M2C_UNK func_3768A0(void *);                               /* extern */
M2C_UNK func_3793B0(s32, s32, s32, s32);                   /* extern */
M2C_UNK func_3794C0(s32, void *, s32);                     /* extern */
M2C_UNK func_3795E0(void);                                 /* extern */
M2C_UNK func_3795F0(s32);                                  /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, s32, s32);     /* extern */
s32 func_1814D0(void);                                     /* extern */
s32 func_308030(s32);                                      /* extern */

extern M2C_UNK D_004737E0 __attribute__((section(".data")));

typedef struct {
    u128 q[22];
} ShopWindow;

s32 func_00467D20(s32 arg0, s32 arg1) {
    ShopWindow buf;
    s32 r;

    func_3768A0(&buf);
    r = func_308030(func_1814D0());
    if (r > 0) {
        func_3766A0(&buf, 0x32C9, 1);
        func_00461690(&buf, 0, r, -1);
        func_3794C0(0, &buf, 0);
        func_3793B0(arg0, arg1, 0, 0x17A3);
    } else {
        func_3766A0(&buf, 0x32CA, 1);
        func_376690(&buf, 1);
        func_379760(&buf, &D_004737E0, 1, 0, 1);
        func_3795F0(0xFFFF);
        func_3795E0();
    }
    return 1;
}
