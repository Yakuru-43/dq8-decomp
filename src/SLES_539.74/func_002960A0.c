// range: 0x2960A0 0x2960E0
#include "common.h"

struct Owner;

extern s32 func_00296640(struct Owner *owner);
extern s32 func_002960E0(struct Owner *owner);

/* restart the selected group if it is the "active" kind */
s32 func_002960A0(struct Owner *owner) {
    s32 ret;

    if ((func_00296640(owner) & 0xFF) == 1) {
        ret = func_002960E0(owner);
    } else {
        ret = 0;
    }
    return ret;
}
