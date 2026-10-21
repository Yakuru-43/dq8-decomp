// range: 0x296140 0x296180
#include "common.h"

struct Owner;

extern s32 func_00296640(struct Owner *owner);
extern s32 func_00296180(struct Owner *owner);

/* query the selected group if it is the "active" kind */
s32 func_00296140(struct Owner *owner) {
    s32 ret;

    if ((func_00296640(owner) & 0xFF) == 1) {
        ret = func_00296180(owner);
    } else {
        ret = 0;
    }
    return ret;
}
