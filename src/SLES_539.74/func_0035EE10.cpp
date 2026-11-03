// range: 0x35EE10 0x35EF20
// rodata: 0x3D3EF0 0x3D3FC4
#include "common.h"

extern "C" {

extern s32 func_001814D0(void);
extern s32 func_002B0CF0(s32, s32);
extern M2C_UNK *func_002C1740(void);
extern s32 func_002C17B0(void);
extern s32 func_002C17F0(void);

static inline s32 GetIdx(void) {
    return *(s32 *)((char *)func_002C1740() + 0x14);
}

s32 func_0035EE10(void) {
    bool hit;
    s32 idx;

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
            idx = GetIdx();
        } else {
            idx = -1;
        }
        return func_002B0CF0(func_001814D0() + 0x5890, idx);
    }
    return 0;
}

}
