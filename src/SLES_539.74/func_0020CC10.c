// range: 0x20CC10 0x20CC40
#include "common.h"

char *func_0020CC10(void *arg0) {
    char *obj;
    char *slot;
    s32 idx;

    obj = arg0;
    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = obj + idx * 0xC0 + 0x5610;
    }
    return slot;
}
