// range: 0x263D60 0x263DA0
#include "common.h"

void func_00222320(void *arg0, u8 arg1);
extern void *D_003E0D08;

void func_00263D60(u32 arg0) {
    void *obj;

    obj = D_003E0D08;
    if (obj != 0) {
        func_00222320(obj, !(arg0 > 0));
    }
}
