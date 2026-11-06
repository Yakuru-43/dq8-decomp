// range: 0x383630 0x383730
#include "common.h"

extern s8 D_003E15C0;
extern M2C_UNK *func_002D34C0(void);
extern s32 func_002D5360(void *, s32, s32);
extern void func_002D5290(void *, s32, s32 *, s32 *);
extern void func_002D5300(void *, s32, s32, s32);

void func_00383630(void) {
    void *obj;
    s32 count;
    s32 val1;
    s32 ext1;
    s32 val2;
    s32 ext2;

    obj = func_002D34C0();
    count = func_002D5360(obj, 0x13BD, 0);
    if (count >= 0x173) {
        func_002D5290(obj, 0x13BD, &val1, &ext1);
        func_002D5290(obj, 0x13BE, &val2, &ext2);
        if (D_003E15C0 > 0x3C) {
            if (val2 > 0x1E) {
                func_002D5300(obj, 0x13BD, val1 - 2, ext1);
                func_002D5300(obj, 0x13BE, val2 - 2, ext2);
            } else {
                func_002D5300(obj, 0x13BD, 30, ext1);
                func_002D5300(obj, 0x13BE, count + 0xA0, ext2);
                D_003E15C0 = 0;
            }
        } else {
            D_003E15C0 = D_003E15C0 + 1;
        }
    }
}
