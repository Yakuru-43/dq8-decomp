// range: 0x45F270 0x45F300
#include "common.h"

struct Msg {
    s16 kind;
    f32 scale;
    u8 pad08[8];
    u8 unk10[0x10];
    u8 unk20[0x10];
    u8 unk30[0x10];
    s16 state;
    u8 pad42[6];
    void *target;
    u8 pad4C[4];
};

extern s32 D_003E1B58;
extern s32 D_003E1B5C;
extern s32 D_003E1B60;
extern struct Msg *D_003E1B64;
extern u32 func_0045F300(u32);
extern struct Msg *func_0014E130(void *, s32);

void func_0045F270(void *arg0) {
    struct Msg *msg;
    s32 i;

    if (arg0 != 0 && D_003E1B58 != 0 && D_003E1B5C != 0 && D_003E1B60 != 0) {
        D_003E1B64 = func_0014E130(arg0, func_0045F300(0x500));
        msg = D_003E1B64;
        i = 0;
        do {
            msg->kind = 0;
            i = i + 1;
            msg->state = -1;
            msg = msg + 1;
        } while (i < 16);
    }
}
