// range: 0x292F20 0x292F60
#include "common.h"

struct Owner;

extern s32 func_00296590(struct Owner *owner);
extern s32 func_00294E30(struct Owner *owner);

/* start the selected group running if it is the "active" kind */
s32 func_00292F20(struct Owner *owner) {
    s32 ret;

    if ((func_00296590(owner) & 0xFF) == 1) {
        ret = func_00294E30(owner);
    } else {
        ret = 0;
    }
    return ret;
}
