// range: 0x1F0750 0x1F0780
#include "common.h"

s32 func_001F0750(void **arg0) {
    void *node;
    s32 count;

    node = *arg0;
    count = 1;
    while (node != 0) {
        node = *(void **)node;
        count += 1;
    }
    return count;
}
