// range: 0x201DC0 0x201E70
#include "common.h"

char *func_00181420(void);
s32 func_00205D30(char *, s32);
s32 func_00206080(char *, s32);
s32 func_00205050(char *, s32, s32);

s32 func_00201DC0(void) {
    char *obj;
    s32 count;
    s32 idx;
    s32 val;

    obj = func_00181420();
    if (obj == 0) {
        return 0;
    }
    count = 0;
    idx = 0;
    do {
        val = func_00205D30(obj, idx);
        if (func_00206080(obj, val) != 0) {
            if (func_00205050(obj, val, 1) > 0) {
                count++;
            }
        }
        idx++;
    } while (idx < 4);
    return count;
}
