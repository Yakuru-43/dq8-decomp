// range: 0x35F200 0x35F270
// rodata: 0x3D4200 0x3D4264
#include "common.h"

extern s32 func_002C17F0(void);
extern s32 func_002C17B0(void);

s32 func_0035F200(void) {
    if (func_002C17F0() == 0) {
        return 0;
    }
    switch (func_002C17B0()) {
    case 0x238C:
    case 0x238D:
    case 0x238E:
    case 0x238F:
    case 0x2390:
    case 0x2391:
    case 0x2392:
    case 0x2393:
    case 0x2394:
    case 0x2395:
    case 0x2396:
    case 0x2397:
    case 0x2398:
    case 0x2399:
    case 0x239A:
    case 0x239B:
    case 0x239C:
    case 0x239D:
    case 0x239E:
    case 0x239F:
    case 0x23A0:
    case 0x23A1:
    case 0x23A2:
    case 0x23A3:
    case 0x23A4:
        return 1;
    }
    return 0;
}
