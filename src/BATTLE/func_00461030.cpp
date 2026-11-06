// range: 0x461030 0x461100
#include "common.h"

extern "C" {

struct MsgTarget {
    u8 pad0[0x1B0];
    virtual s32 f0();
    virtual s32 f1();
    virtual s32 f2();
    virtual s32 f3();
    virtual s32 f4();
    virtual s32 f5();
    virtual s32 f6();
    virtual s32 f7();
    virtual s32 f8();
    virtual s32 f9();
    virtual s32 f10();
    virtual s32 f11();
    virtual s32 f12();
    virtual s32 f13();
    virtual s32 f14();
    virtual s32 f15();
    virtual s32 f16();
    virtual s32 f17();
    virtual s32 request(); /* slot 0x50 */
};

typedef struct {
    /* 0x00 */ s32 handle;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ void *unk0C;
    /* 0x10 */ void *unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ u8 pad1C[0x88 - 0x1C];
} S_request;

extern MsgTarget *D_003E1B70;
extern s32 D_003DFBC0;
extern M2C_UNK D_00483F90 __attribute__((section(".data")));

extern MsgTarget *func_14EB30(s32 size, void *arg1);
extern MsgTarget *func_0045F4E0(MsgTarget *self);
extern void func_0045F5E0(S_request *self);
extern s32 func_161E80(s32, M2C_UNK *, s32 *);
extern s32 func_286970(MsgTarget *, S_request *);

void func_00461030(void *arg0, s32 arg1, s32 arg2) {
    S_request req;
    MsgTarget *handle;
    s32 result;

    handle = func_14EB30(0x4F0, arg0);
    if (handle != 0) {
        handle = func_0045F4E0(handle);
    }
    D_003E1B70 = handle;
    result = func_161E80(arg2, &D_00483F90, 0);
    if (D_003E1B70 != 0 && result != 0) {
        D_003E1B70->request();
        func_0045F5E0(&req);
        req.handle = result;
        req.unk04 = D_003DFBC0;
        req.unk08 = arg0;
        req.unk0C = arg0;
        req.unk10 = arg0;
        req.unk14 = arg1;
        req.unk18 = 1;
        func_286970(D_003E1B70, &req);
    }
}

}
