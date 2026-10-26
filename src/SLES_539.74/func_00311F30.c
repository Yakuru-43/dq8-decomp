// range: 0x311F30 0x311FD0
#include "common.h"

char *func_00181420(void);
s32 func_00206080(void *, s32);
void func_00203310(s32, s32, s8);

void func_00311F30(s32 arg0, s8 arg1) {
    void *obj;
    s32 i;

    obj = func_00181420();
    if (arg0 == 4) {
        for (i = 1; i < 4; i++) {
            if (func_00206080(obj, i) != 0) {
                func_00203310((s32)obj, i, arg1);
            }
        }
    } else {
        func_00203310((s32)obj, arg0, arg1);
    }
}
