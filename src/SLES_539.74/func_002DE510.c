// range: 0x2DE510 0x2DE550
#include "common.h"

extern void func_00376080(void *);

typedef struct {
    u8 pad_0[0x70];
    void *field_70;
} Obj;

void func_002DE510(Obj *arg0) {
    void *temp_a0;

    temp_a0 = arg0->field_70;
    if (temp_a0 != 0) {
        func_00376080(temp_a0);
    }
    arg0->field_70 = 0;
}
