// range: 0x218710 0x218740
// auto: m2c, verified byte-exact
#include "common.h"

void *func_00218710(void *arg0) {
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
