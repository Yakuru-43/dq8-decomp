// range: 0x1FFA40 0x1FFA50
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern s32 D_003E0834;
extern int func_001575A0();

int func_001FFA40(void * arg0) {
    return func_001575A0(D_003E0834);
}
