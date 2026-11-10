// range: 0x292E00 0x292E70
#include "common.h"

extern s32 func_00296640(void *owner);
extern void func_00292460(void *owner, u32 flags);
extern s32 func_002915F0(void *owner, s32 index);
extern void func_00291400(void *owner);

s32 func_00292E00(void *owner) {
    s32 flags;

    if ((func_00296640(owner) & 0xFF) == 1) {
        flags = 0x10;
        func_00292460(owner, flags);
        if (func_002915F0(owner, 0) > 0) {
            func_00291400(owner);
            return 1;
        }
    }
    return 0;
}
