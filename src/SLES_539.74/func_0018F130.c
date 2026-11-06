// range: 0x18F130 0x18F230
#include "common.h"

extern u16 D_003E053C;
extern s32 D_003E0540;
extern s32 func_0012D528(char *);
extern s32 func_00133F78(s32, char *);

s32 func_0018F130(char *name) {
    s32 i;
    s32 base;
    s32 handle;
    s32 val;

    if (name == 0) {
        return -1;
    }
    if (name[1] == '_') {
        if (name[0] >= 'a' && name[0] < 'w' && name[2] >= '0' && name[2] < '3') {
            val = func_0012D528(name + 2);
            if (0 <= val && val < 0x1C) {
                return 0x1B;
            }
            return -1;
        }
    }
    base = D_003E0540;
    for (i = 0; i < (s32)D_003E053C; i++, base += 0x1C) {
        handle = *(s32 *)base;
        if (handle != 0) {
            if (func_00133F78(handle, name) == 0) {
                return i;
            }
        }
    }
    return -1;
}
