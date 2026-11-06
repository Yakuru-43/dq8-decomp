// range: 0x0035ED10 0x0035EE10
// rodata: 0x3D3E10 0x3D3EE4
#include "common.h"

extern "C" {

extern s32 func_002C17B0(void);
extern s32 func_002C17F0(void);

s32 func_0035ED10(void) {
    bool hit;

    if (func_002C17F0() != 0) {
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
            hit = true;
            break;
        default:
            hit = false;
            break;
        }
    } else {
        hit = false;
    }
    if (hit) {
        switch (func_002C17B0()) {
        case 0x238C:
        case 0x238D:
        case 0x238E:
            return 7;
        case 0x238F:
        case 0x2390:
        case 0x2391:
            return 6;
        case 0x2392:
        case 0x2393:
        case 0x2394:
            return 5;
        case 0x2395:
        case 0x2396:
        case 0x2397:
            return 4;
        case 0x2398:
        case 0x2399:
        case 0x239A:
            return 3;
        case 0x239B:
        case 0x239C:
        case 0x239D:
            return 2;
        case 0x239E:
        case 0x239F:
        case 0x23A0:
            return 1;
        case 0x23A1:
        case 0x23A2:
        case 0x23A3:
            return 0;
        case 0x23A4:
            return 0;
        default:
            return -1;
        }
    }
    return -1;
}

}
