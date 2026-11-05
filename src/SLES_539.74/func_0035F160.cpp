// range: 0x35F160 0x35F200
// rodata: 0x3D4190 0x3D41F4
#include "common.h"

extern "C" {

extern M2C_UNK *func_002C1740(void);
extern s32 func_002C17B0(void);
extern s32 func_002C17F0(void);

s32 func_0035F160(void) {
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
        if (*(s32 *)((char *)func_002C1740() + 0x10) == 2) {
            return 1;
        }
    }
    return 0;
}

}
