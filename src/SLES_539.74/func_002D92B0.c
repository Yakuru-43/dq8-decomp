// range: 0x2D92B0 0x2D9320
#include "common.h"

void func_00151AB0(void);
void func_00151A20(void *, char *);
void func_00151990(void *, char *);
void func_002D92A0(void *, f32);

void func_002D92B0(void *arg0, char *arg1) {
    if (arg0 != NULL && arg1 != NULL) {
        func_00151AB0();
        func_00151A20(arg0, arg1 + 0x10);
        func_00151990(arg0, arg1 + 0x20);
        func_002D92A0(arg0, *(f32 *)(arg1 + 0x34));
    }
}
