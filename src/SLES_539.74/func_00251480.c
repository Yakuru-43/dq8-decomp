// range: 0x251480 0x2514B0
#include "common.h"

void *func_00251480(char *arg0, u32 arg1) {
    if (arg1 >= *(u32 *)(arg0 + 8)) {
        return 0;
    }
    return *(char **)(arg0 + 4) + arg1;
}
