// range: 0x350B80 0x350BC0
// auto: m2c, verified byte-exact
#include "common.h"

s32 func_00350B80(s32 arg0, s32 arg1) {
    if ((arg1 >= 0) && (arg1 < 2)) {
        return arg0 + (arg1 * 0xA4) + 0x19A4;
    }
    return 0;
}
