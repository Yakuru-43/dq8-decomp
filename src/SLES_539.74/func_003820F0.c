// range: 0x3820F0 0x3821D0
#include "common.h"

extern void *func_002D34C0(void);
extern void func_001FFA50(void *, void *, void *);
extern void func_002D7120(void *, s32, s32, s32);
extern void func_002D4240(void *, s32, s32, s32);
extern void func_002D6D70(void *, s32, s32);
extern void func_002D4B30(void *, s32);

void func_003820F0(s32 arg0, void *arg1, void *arg2, void *arg3) {
    void *s0;

    s0 = func_002D34C0();
    func_001FFA50(arg1, arg2, arg3);
    func_002D7120(s0, 0x1438, 0x14, 0x139);
    if (arg0 != 0) {
        func_002D4240(s0, 0x1438, 1, 1);
        func_002D6D70(s0, 0x138C, 1);
        func_002D6D70(s0, 0x138D, 1);
    } else {
        func_002D4240(s0, 0x1438, 0, 1);
    }
    func_002D4B30(s0, 0x1421);
}
