// range: 0x36E160 0x36E1D0
#include "common.h"

extern s32 func_0036E260(void);

s32 func_0036E160(char *arg0) {
    void *temp_v0;
    s16 temp_v1;

    temp_v0 = *(void **)(arg0 + 0x578);
    if (temp_v0 == NULL) {
        return 1;
    }
    if (*(s32 *)((char *)temp_v0 + 0x24) == 0) {
        if (func_0036E260() != 0) {
            return 1;
        }
    }
    temp_v1 = *(s16 *)(arg0 + 0x588);
    if (temp_v1 == 2) {
        return 1;
    }
    return 0;
}
