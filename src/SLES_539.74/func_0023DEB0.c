// range: 0x23DEB0 0x23DF20
#include "common.h"

s32 func_001E7360(s32, s32);
extern char *D_003E0B24;

typedef struct {
    /* 0x00 */ s32 field_00;
    /* 0x04 */ s32 *field_04;
} S_23DEB0;

s32 func_0023DEB0(S_23DEB0 *arg0, s32 arg1) {
    s32 *ptr;
    s32 ret;

    if (arg1 != 1) {
        return 0;
    }
    ptr = *(s32 **)(D_003E0B24 + 8);
    if (ptr == 0) {
        return 0;
    }
    ret = func_001E7360((s32)ptr + 0x1F0, -1);
    if (arg0->field_00 == 3) {
        ptr = arg0->field_04;
        ptr[1] = ret;
    }
    return 1;
}
