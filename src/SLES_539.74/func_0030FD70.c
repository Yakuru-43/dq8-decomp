// range: 0x30FD70 0x30FE30
#include "common.h"

struct Desc {
    u8 kind;
    char pad1[0x1F];
    s32 flags;
};

extern s32 func_0035BDC0(void *arg0, u32 arg1);
extern s32 func_0035BF00(void *arg0, s32 arg1);
extern s32 func_0030B890(void *arg0, long arg1);

s32 func_0030FD70(void *arg0, struct Desc *arg1) {
    s32 kind = func_0035BDC0(arg0, arg1->kind);
    if (func_0035BF00(arg0, kind) == 0) {
        return 0;
    }
    if (arg1->flags & 2) {
        if (func_0030B890(arg0, 0x8000) != 0) {
            return 0;
        }
    }
    if (arg1->flags & 4) {
        if ((func_0030B890(arg0, 0x4000) | func_0030B890(arg0, 0x800000000)) != 0) {
            return 0;
        }
    }
    return 1;
}
