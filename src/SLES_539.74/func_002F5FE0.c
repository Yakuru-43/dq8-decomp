// range: 0x2F5FE0 0x2F6010
#include "common.h"

struct WinTbl {
    char pad[0x1518];
    s32 slots[0x10];
};

void func_002F5FE0(struct WinTbl *arg0, s32 arg1, s32 arg2) {
    if (arg1 < 0) {
        return;
    }
    if (!(arg1 < 0x10)) {
        return;
    }
    arg0->slots[arg1] = arg2;
}
