// range: 0x348D80 0x348DB0
#include "common.h"

extern char *D_003E134C;

s32 *func_00348D80(s32 *arg0) {
    if (D_003E134C == NULL) {
        return NULL;
    }
    *arg0 = *(s32 *)D_003E134C;
    return (s32 *)(D_003E134C + 0x10);
}
