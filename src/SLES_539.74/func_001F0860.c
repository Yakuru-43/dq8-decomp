// range: 0x1F0860 0x1F0890
// auto: m2c, verified byte-exact
#include "common.h"

void *func_001F0860(void *arg0) {
    void *next;

    while (arg0 != 0) {
        next = *(void **)arg0;
        if (next == 0) {
            break;
        }
        arg0 = next;
    }
    return arg0;
}
