// range: 0x208650 0x2086A0
#include "common.h"

void func_003727A0(char *);

void func_00208650(char *arg0) {
    char *slot;
    s32 idx;

    idx = M2C_FIELD(arg0, s32 *, 0x5874);
    if (idx < 0) {
        slot = 0;
    } else {
        slot = arg0 + idx * 0x6C + 0x5790;
    }
    if (slot != 0) {
        func_003727A0(slot);
    }
}
