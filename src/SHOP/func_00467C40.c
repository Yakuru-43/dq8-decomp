// range: 0x467C40 0x467D20
#include "common.h"

M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);         /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);                /* extern */
M2C_UNK func_3766A0(void *, s32, s32);                        /* extern */
M2C_UNK func_3768A0(void *);                                  /* extern */
M2C_UNK func_3791B0(void *);                                  /* extern */
M2C_UNK func_3794B0(void);                                    /* extern */
M2C_UNK func_379760(void *, M2C_UNK *, s32, s32, s32);        /* extern */

extern M2C_UNK D_00473820 __attribute__((section(".data")));
extern M2C_UNK D_00473890 __attribute__((section(".data")));

typedef struct {
    char pad0[0x20];
    s32 unk20;
} S_arg0;

typedef struct {
    u128 pad0;
    char pad10[0x150];
} ShopWindow;

s32 func_00467C40(S_arg0 *arg0, s32 arg1) {
    ShopWindow buf;
    s32 r;

    if (func_3791B0(arg0) != 1) { return 1; }
    r = func_3794B0();
    func_2D38E0(arg1, 0x17A3, 0, -1);
    if (r == 0) {
        func_3768A0(&buf);
        func_3766A0(&buf, 0x32CE, 1);
        func_379760(&buf, &D_00473890, 1, 0, 1);
    } else if (r == 1) {
        func_370C00(arg0->unk20, &D_00473820, 0);
    }
    return 1;
}
