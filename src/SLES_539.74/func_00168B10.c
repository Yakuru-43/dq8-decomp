// range: 0x168B10 0x168BE0
#include "common.h"

void func_001007A0(void *);
void *func_00169540(void *, s64);

void *func_00168B10(void *arg0, s64 arg1) {
    void *temp_a0;

    if (arg0 != NULL) {
        if ((char *)arg0 + 0x18 != NULL) {
            if ((char *)arg0 + 0x18 != NULL) {
                if ((char *)arg0 + 0x18 != NULL) {
                    temp_a0 = *(void **)((char *)arg0 + 0x20);
                    if (temp_a0 != NULL) {
                        func_001007A0(temp_a0);
                    }
                }
            }
        }
        if ((char *)arg0 + 0xC != NULL) {
            if ((char *)arg0 + 0xC != NULL) {
                if ((char *)arg0 + 0xC != NULL) {
                    temp_a0 = *(void **)((char *)arg0 + 0x14);
                    if (temp_a0 != NULL) {
                        func_001007A0(temp_a0);
                    }
                }
            }
        }
        if (arg0 != NULL) {
            if (arg0 != NULL) {
                func_00169540(arg0, 0);
            }
        }
        if (((s64)(arg1 << 0x30) >> 0x30) > 0) {
            func_001007A0(arg0);
        }
    }
    return arg0;
}
