// range: 0x1F6FB0 0x1F6FF0
#include "common.h"

s32 func_001F6FB0(s32 *arg0, s32 arg1) {
    s32 count = *(s32 *)((char *)arg0 + 0x4E4);
    s32 *arr = *(s32 **)((char *)arg0 + 0x4E8);
    if ((arg1 >= 0) && (arg1 < count)) {
        return arr[arg1];
    }
    return 0;
}
