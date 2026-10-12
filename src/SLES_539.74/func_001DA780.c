// range: 0x1DA780 0x1DA790
// auto: tail-call thunk, verified byte-exact
#include "common.h"

extern int func_00339A20();

int func_001DA780(void * arg0) {
    return func_00339A20((char *)arg0 + 0x6B34);
}
