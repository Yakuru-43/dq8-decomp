// range: 0x295B70 0x295BB0
#include "common.h"

struct Owner;

extern s32 func_00296590(struct Owner *owner);
extern s32 func_00295BB0(struct Owner *owner);

/* pause the selected group if it is the "active" kind */
s32 func_00295B70(struct Owner *owner) {
    s32 ret;

    if ((func_00296590(owner) & 0xFF) == 1) {
        ret = func_00295BB0(owner);
    } else {
        ret = 0;
    }
    return ret;
}
