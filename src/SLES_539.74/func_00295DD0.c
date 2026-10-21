// range: 0x295DD0 0x295E10
#include "common.h"

struct Owner;

extern s32 func_00296640(struct Owner *owner);
extern s32 func_00295E10(struct Owner *owner);

/* stop the selected group if it is the "active" kind */
s32 func_00295DD0(struct Owner *owner) {
    s32 ret;

    if ((func_00296640(owner) & 0xFF) == 1) {
        ret = func_00295E10(owner);
    } else {
        ret = 0;
    }
    return ret;
}
