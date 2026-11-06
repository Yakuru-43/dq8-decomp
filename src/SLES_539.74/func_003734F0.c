// range: 0x3734F0 0x373580
#include "common.h"

M2C_UNK *func_002D34C0(void);
void func_002D45D0(s32, s32, M2C_UNK, M2C_UNK);

void func_003734F0(s32 arg0, s32 arg1) {
    s32 unk;
    s32 node;

    unk = (s32)func_002D34C0();
    node = arg0 + 0x186A8;
    if (arg1 == 0) {
        func_002D45D0(unk, node, 8, 1);
    }
    if (arg1 == 1) {
        func_002D45D0(unk, node, 0xB, 1);
    }
}
