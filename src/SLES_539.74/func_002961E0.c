// range: 0x2961E0 0x296220
#include "common.h"

struct Owner;

extern s32 func_00296590(struct Owner *owner);
extern s32 func_00296220(struct Owner *owner);

/* check the selected group if it is the "active" kind */
s32 func_002961E0(struct Owner *owner) {
    s32 ret;

    if ((func_00296590(owner) & 0xFF) == 1) {
        ret = func_00296220(owner);
    } else {
        ret = 0;
    }
    return ret;
}
