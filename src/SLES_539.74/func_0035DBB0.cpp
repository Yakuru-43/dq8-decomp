// range: 0x35DBB0 0x35DC80
#include "common.h"

extern "C" {

typedef struct {
    char pad0[0x158];
    u64 flags158;
} S_obj;

s32 func_0035E570(void *);
s32 func_00201760(void *, s32 *);

bool func_0035DBB0(S_obj *arg0, s32 arg1, s32 arg2) {
    bool ret;

    ret = true;
    if (func_0035E570(arg0) != 0) {
        ret = false;
    }
    if (func_00201760(arg0, 0) <= 0 || (arg0->flags158 & 0x2008001E) != 0) {
        ret = false;
    }
    if (arg1 == 0 && (arg0->flags158 & 0x40000) != 0) {
        ret = false;
    }
    if (arg2 == 0 && (arg0->flags158 & 0x20000) != 0) {
        ret = false;
    }
    return ret;
}

}
