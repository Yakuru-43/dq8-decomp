// range: 0x45F040 0x45F110
#include "common.h"

extern "C" {

struct MsgTarget {
    u8 pad0[0x1B0];
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
    virtual s32 f3();
    virtual void set_scale(f32);   /* slot 0x18 */
    virtual s32 f5();
    virtual s32 f6();
    virtual void update();         /* slot 0x24 */
};

struct Msg {
    s16 kind;
    f32 scale;
    u8 pad08[8];
    u8 unk10[0x10];
    u8 unk20[0x10];
    u8 unk30[0x10];
    u8 pad40[8];
    MsgTarget *target;
    u8 pad4C[4];
};

extern Msg *D_003E1B64;
extern void func_151AB0(void *, void *);
extern void func_151990(void *, void *);
extern void func_151A20(void *, void *);
extern void func_288AA0(void *, f32);
extern void func_2889C0(void *, f32);

void func_0045F040(void) {
    Msg *msg;
    s32 i;

    msg = D_003E1B64;
    if (msg == 0) {
        return;
    }
    i = 0;
    do {
        if (msg->kind != 0) {
            if (msg->target != 0) {
                func_151AB0(msg->target, msg->unk20);
                func_151990(msg->target, msg->unk10);
                func_151A20(msg->target, msg->unk30);
                func_288AA0(msg->target, msg->scale);
                func_2889C0(msg->target, 1.0f);
                msg->target->set_scale(1.0f);
                msg->target->update();
            }
        }
        i = i + 1;
        msg = msg + 1;
    } while (i < 16);
}

}
