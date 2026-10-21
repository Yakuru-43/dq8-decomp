// range: 0x295A50 0x295A90
#include "common.h"

struct Owner;

extern s32 func_00296640(struct Owner *owner);
extern s32 func_00295A90(struct Owner *owner);

/* start the selected group running if it is the "active" kind */
s32 func_00295A50(struct Owner *owner) {
    s32 ret;

    if ((func_00296640(owner) & 0xFF) == 1) {
        ret = func_00295A90(owner);
    } else {
        ret = 0;
    }
    return ret;
}
