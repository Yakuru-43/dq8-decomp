// range: 0x356880 0x3568B0
#include "common.h"

f32 func_00356880(char *arg0) {
    s8 tag;
    tag = *(s8 *)(arg0 + 4);
    if (tag == 1) {
        return *(f32 *)arg0;
    }
    if (tag == 0) {
        return (f32)*(s32 *)arg0;
    }
    return 0.0f;
}
