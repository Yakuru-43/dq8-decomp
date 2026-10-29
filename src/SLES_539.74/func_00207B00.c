// range: 0x207B00 0x207B20
#include "common.h"

s32 func_00207B00(char *arg0, u32 arg1) {
    s64 val = *(s64 *)(arg0 + 0x28);
    s64 mask = (s64)arg1;
    return (val & mask) != 0;
}
