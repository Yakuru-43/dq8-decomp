// range: 0x16B960 0x16BA20
#include "common.h"

static inline void clear_54(char *obj, s32 idx) {
    char *p;

    if ((idx >= 0) && (idx < 14)) {
        p = obj + (idx * 0x58) + 0x38;
    } else {
        p = NULL;
    }
    if (p != NULL) {
        *(s32 *)(p + 0x54) = 0;
    }
}

void func_0016B960(char *arg0, s32 arg1) {
    s32 i;

    if (arg1 < 0) {
        i = 0;
        do {
            clear_54(arg0, i);
        } while (++i < 14);
    } else {
        clear_54(arg0, arg1);
        return;
    }
}
