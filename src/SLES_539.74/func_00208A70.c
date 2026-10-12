// range: 0x208A70 0x208A80
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00372AA0();

int func_00208A70(void * arg0) {
    return func_00372AA0((char *)arg0 + 0x5790);
}
