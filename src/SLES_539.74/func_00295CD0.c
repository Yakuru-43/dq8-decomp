// range: 0x295CD0 0x295D10
#include "common.h"

struct Owner;

extern s32 func_00296640(struct Owner *owner);
extern s32 func_00295D10(struct Owner *owner);

/* resume the selected group if it is the "active" kind */
s32 func_00295CD0(struct Owner *owner) {
    s32 ret;

    if ((func_00296640(owner) & 0xFF) == 1) {
        ret = func_00295D10(owner);
    } else {
        ret = 0;
    }
    return ret;
}
