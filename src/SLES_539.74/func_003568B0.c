// range: 0x3568B0 0x3568E0
#include "common.h"

s32 func_003568B0(char *arg0) {
    s8 tag;

    tag = *(s8 *)(arg0 + 4);
    if (tag == 0) {
        return *(s32 *)arg0;
    }
    if (tag == 1) {
        return (s32)*(f32 *)arg0;
    }
    return 0;
}
