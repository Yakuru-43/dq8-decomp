// range: 0x2F8D30 0x2F9040
// rodata: 0x3CFB00 0x3CFB78
#include "common.h"

extern u32 func_002F9350(s32);
extern s32 func_002F9720(s32, s32, s32);
extern s32 func_002F99F0(s32, s32, s32);
extern s32 func_002FA4E0(s32);
extern s32 func_002FA7B0(s32, s32);
extern s32 func_002FAA80(s32, s32);
extern s32 func_002FACE0(s32, s32, s32);
extern s32 func_002FAFE0(s32, s32, s32);
extern s32 func_002FB2E0(s32);
extern s32 func_002FC800(s32, s32, s32);
extern s32 func_002FCD20(s32, s32);
extern s32 func_002FD250(s32, s32);
extern s32 func_002FD780(s32, s32, s32);

void func_002F8D30(s32 arg0, s32 arg1) {
    s32 keep;

    if (arg1 == 0) {
        return;
    }
    keep = 1;
    while (keep != 0) {
        keep = 0;
        switch (func_002F9350(arg1)) {
        case 1:
            keep = func_002FD780(arg0, arg1, 1);
            break;
        case 2:
            keep = func_002FD780(arg0, arg1, 2);
            break;
        case 3:
            keep = func_002FD250(arg0, arg1);
            break;
        case 4:
            keep = func_002FCD20(arg0, arg1);
            break;
        case 5:
            keep = func_002FC800(arg0, arg1, 1);
            break;
        case 6:
            keep = func_002FC800(arg0, arg1, 2);
            break;
        case 7:
            keep = func_002FB2E0(arg1);
            break;
        case 8:
            keep = func_002F9720(arg0, arg1, 1);
            break;
        case 9:
            keep = func_002F9720(arg0, arg1, 2);
            break;
        case 10:
            keep = func_002F9720(arg0, arg1, 3);
            break;
        case 11:
            keep = func_002F9720(arg0, arg1, 4);
            break;
        case 12:
            keep = func_002F9720(arg0, arg1, 5);
            break;
        case 13:
            keep = func_002FD780(arg0, arg1, 4);
            break;
        case 14:
            keep = func_002FD780(arg0, arg1, 5);
            break;
        case 15:
            keep = func_002FD780(arg0, arg1, 6);
            break;
        case 16:
            keep = func_002FD780(arg0, arg1, 7);
            break;
        case 17:
            keep = func_002FD780(arg0, arg1, 8);
            break;
        case 18:
            keep = func_002FC800(arg0, arg1, 3);
            break;
        case 19:
            keep = func_002FAFE0(arg0, arg1, 1);
            break;
        case 20:
            keep = func_002FAFE0(arg0, arg1, 2);
            break;
        case 21:
            keep = func_002FAFE0(arg0, arg1, 3);
            break;
        case 22:
            keep = func_002FACE0(arg0, arg1, 4);
            break;
        case 23:
            keep = func_002FACE0(arg0, arg1, 5);
            break;
        case 24:
            keep = func_002FACE0(arg0, arg1, 1);
            break;
        case 25:
            keep = func_002FACE0(arg0, arg1, 2);
            break;
        case 26:
            keep = func_002FAA80(arg0, arg1);
            break;
        case 27:
            keep = func_002FA7B0(arg0, arg1);
            break;
        case 28:
            keep = func_002FA4E0(arg1);
            break;
        case 29:
            keep = func_002F99F0(arg0, arg1, 1);
            break;
        default:
            break;
        }
    }
}
