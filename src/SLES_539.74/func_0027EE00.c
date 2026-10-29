// range: 0x27EE00 0x27EE50
#include "common.h"

extern char *D_003E0DE4;

s16 *func_0027EE00(s32 arg0) {
    s16 *result;
    s32 i;
    s16 *base;
    s16 count;

    result = NULL;
    if (D_003E0DE4 == NULL) {
        return result;
    }

    base = (s16 *)(D_003E0DE4 + 0x24);
    count = *(s16 *)(D_003E0DE4 + 0x20);
    i = 0;

    while (i < count) {
        s16 *elem = base + (i << 3);
        if (arg0 == *elem) {
            return elem;
        }
        i++;
    }

    return result;
}
