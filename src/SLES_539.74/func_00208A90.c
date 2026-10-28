// range: 0x208A90 0x208AD0
#include "common.h"

char *func_00208A90(char *arg0) {
    char *slot;
    s32 idx;

    idx = *(s32 *)(arg0 + 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = arg0 + idx * 0x6C + 0x5790;
    }
    return slot;
}
