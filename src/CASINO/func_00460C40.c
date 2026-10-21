// range: 0x460C40 0x460C50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_2F7540(void *, float);

int func_00460C40(void * arg0, float arg1) {
    *(float *)((char *)arg0 + 0x2330) = arg1;
    return func_2F7540(arg0, arg1);
}
