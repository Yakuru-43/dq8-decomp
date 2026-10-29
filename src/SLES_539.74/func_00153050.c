// range: 0x153050 0x153080
#include "common.h"

s32 func_00153050(void *arg0, s32 arg1) {
    void *node;
    s32 count;
    void *field;

    node = *(void **)((char *)arg0 + 0x44);
    count = 0;
    while (node != NULL) {
        field = (char *)node + 0x10;
        if (field != NULL) {
            *(s32 *)field = arg1;
            count++;
        }
        node = *(void **)node;
    }
    return count;
}
