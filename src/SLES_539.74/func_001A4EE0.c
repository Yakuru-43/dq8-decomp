// range: 0x1A4EE0 0x1A4F10
#include "common.h"

s32 func_001AC810(s32, s32);

typedef struct {
    char pad0[0x40];
    s32 unk40;
    char pad44[0x24];
    s32 unk68;
} S_arg1;

u8 func_001A4EE0(s32 arg0, S_arg1 *arg1) {
    return !(func_001AC810(arg1->unk40, arg1->unk68) != 0);
}
