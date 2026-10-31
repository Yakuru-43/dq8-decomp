// range: 0x467710 0x4677D0
#include "common.h"

M2C_UNK func_2D38E0(s32, M2C_UNK, M2C_UNK, M2C_UNK);             /* extern */
M2C_UNK func_370C00(s32, M2C_UNK *, M2C_UNK);                    /* extern */
extern M2C_UNK D_00473890 __attribute__((section(".data")));
extern M2C_UNK D_004738C0 __attribute__((section(".data")));

typedef struct {
    char pad0[0x10];
    s16 unk10;
} S_18;

typedef struct {
    char pad0[0x18];
    S_18 *unk18;
    char pad1C[4];
    s32 unk20;
} S_obj;

M2C_UNK func_3791B0(S_obj *);                                     /* extern */
M2C_UNK func_3794B0(void);                                        /* extern */

s32 func_00467710(S_obj *arg0, s32 arg1) {
    s32 r;

    if (arg0->unk18->unk10 != 0 || func_3791B0(arg0) != 1) {
        return 1;
    }
    r = func_3794B0();
    if (r == 0) {
        func_2D38E0(arg1, 0x17A3, 0, -1);
        func_370C00(arg0->unk20, &D_004738C0, 0);
    } else if (r == 1) {
        func_370C00(arg0->unk20, &D_00473890, 0);
    }
    return 1;
}
