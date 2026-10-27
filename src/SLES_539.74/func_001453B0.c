// range: 0x1453B0 0x145440
#include "common.h"

s32 func_001453B0(char *arg0) {
    s32 sp = M2C_FIELD(M2C_FIELD(arg0, char **, 0x270), s32 *, 0x30);

    switch (sp) {
    case 0:
        return 0x20;
    case 1:
        return 0x18;
    case 2:
        return 0x10;
    case 0xA:
        return 0x10;
    case 0x13:
        return 8;
    case 0x14:
        return 4;
    case 0x30:
        return 0x20;
    case 0x31:
        return 0x18;
    case 0x32:
        return 0x10;
    case 0x3A:
        return 0x10;
    }
    return 0x20;
}
