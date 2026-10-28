// range: 0x208270 0x208360
#include "common.h"

void func_00306170(char *);
s32 func_003724B0(char *, s32);
void func_003729D0(char *);

void func_00208270(char *arg0, s32 arg1, s32 arg2) {
    char *obj;
    s32 idx;
    char *p;

    obj = arg0;
    idx = *(s32 *)(arg0 + 0x5874);
    if (idx < 0) {
        p = 0;
    } else {
        p = obj + idx * 0x6C + 0x5790;
    }
    if (p != 0) {
        func_003729D0(p);
        if (arg1 == 1) {
            idx = *(s32 *)(arg0 + 0x5874);
            if (idx < 0) {
                p = 0;
            } else {
                p = obj + idx * 0x6C + 0x5790;
            }
            if (p != 0) {
                func_003724B0(p, 1);
            }
        }
        if (arg2 == 0) {
            idx = *(s32 *)(arg0 + 0x5874);
            if (idx < 0) {
                p = 0;
            } else {
                p = obj + idx * 0xC0 + 0x5610;
            }
            func_00306170(p);
        }
    }
}
