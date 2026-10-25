// range: 0x2F7830 0x2F7A00
// rodata: 0x3CF8B0 0x3CF900
#include "common.h"

/* codes 0xFAE9 down to 0xFAD6: five groups of four */
s32 func_002F7830(u16 code, s32 *major, s32 *minor) {
    if (major == NULL || minor == NULL) {
        return 0;
    }
    switch (code - 0xFA00) {
    case 0xE9:
        *major = 1;
        *minor = 0;
        break;
    case 0xE8:
        *major = 1;
        *minor = 1;
        break;
    case 0xE7:
        *major = 1;
        *minor = 2;
        break;
    case 0xE6:
        *major = 1;
        *minor = 3;
        break;
    case 0xE5:
        *major = 2;
        *minor = 0;
        break;
    case 0xE4:
        *major = 2;
        *minor = 1;
        break;
    case 0xE3:
        *major = 2;
        *minor = 2;
        break;
    case 0xE2:
        *major = 2;
        *minor = 3;
        break;
    case 0xE1:
        *major = 3;
        *minor = 0;
        break;
    case 0xE0:
        *major = 3;
        *minor = 1;
        break;
    case 0xDF:
        *major = 3;
        *minor = 2;
        break;
    case 0xDE:
        *major = 3;
        *minor = 3;
        break;
    case 0xDD:
        *major = 4;
        *minor = 0;
        break;
    case 0xDC:
        *major = 4;
        *minor = 1;
        break;
    case 0xDB:
        *major = 4;
        *minor = 2;
        break;
    case 0xDA:
        *major = 4;
        *minor = 3;
        break;
    case 0xD9:
        *major = 5;
        *minor = 0;
        break;
    case 0xD8:
        *major = 5;
        *minor = 1;
        break;
    case 0xD7:
        *major = 5;
        *minor = 2;
        break;
    case 0xD6:
        *major = 5;
        *minor = 3;
        break;
    default:
        return 0;
    }
    return 1;
}
