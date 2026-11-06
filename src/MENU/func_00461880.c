// range: 0x461880 0x461960
#include "common.h"

s32 func_0045F910(s32);                            /* extern */
void func_00461870(void *, s32, void *);            /* extern */
M2C_UNK func_00461960(void *, M2C_UNK, s16);        /* extern */
s16 func_00465610(void);                            /* extern */
s32 func_181420(void);                              /* extern */
s16 func_206C20(s32, s8, s16);                      /* extern */
M2C_UNK func_36F920(void *, s16, s8);               /* extern */
M2C_UNK func_3766A0(void *, s32, s32);              /* extern */
M2C_UNK func_3768A0(void *);                        /* extern */
M2C_UNK func_3793B0(s32, s32, s32, s32);            /* extern */
M2C_UNK func_3794C0(s32, void *, s32);              /* extern */
s8 func_37AD10(s32);                                /* extern */

extern s8 D_003E1A6C;
extern s16 D_003E1A70;
extern s16 D_003E1A74;
extern s16 D_003E1A78;

typedef struct {
    u128 q[22];
} TextBuf;

typedef struct {
    u128 q[6];
} CmdBuf;

s32 func_00461880(s32 arg0, s32 arg1) {
    TextBuf buf;
    CmdBuf cmd;

    D_003E1A6C = func_37AD10(arg0);
    D_003E1A74 = func_00465610();
    D_003E1A70 =
        func_206C20(func_0045F910(func_181420()), D_003E1A6C, D_003E1A74);
    D_003E1A78 = 0;
    func_3768A0(&buf);
    func_36F920(&cmd, D_003E1A70, D_003E1A6C);
    func_00461870(&buf, 0, &cmd);
    func_00461960(&buf, 0x3F2, D_003E1A70);
    func_3766A0(&buf, 0x3F2, 0);
    func_3794C0(1, &buf, 0);
    func_3793B0(arg0, arg1, 0, 0x18703);
    return 1;
}
