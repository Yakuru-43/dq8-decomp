// Best draft for func_002106E0 (score 14, CLASS structural). See the .md note.
// range: 0x2106E0 0x210730
#include "common.h"

s32 func_0012BC70(void);                              /* extern */

s32 func_002106E0(void) {
    s32 r;
    s32 ret;

    r = func_0012BC70();
    if (r == -0x79) {
        ret = 1;
    } else if (r == -0x78) {
        ret = 1;
    } else if (r == -0x65) {
        ret = 1;
    } else if (r == 0) {
        ret = 0;
    } else {
        ret = 1;
    }
    return ret;
}
