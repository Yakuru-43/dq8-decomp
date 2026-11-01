// range: 0x2F9040 0x2F9350
// rodata: 0x3CFB80 0x3CFBF8
#include "common.h"

extern u32 func_002F9530(s32);
extern s32 func_002F9CE0(s32, s32, s32);
extern s32 func_002FA0F0(s32, s32, s32);
extern s32 func_002FB5E0(s32);
extern s32 func_002FB860(s32, s32);
extern s32 func_002FBB60(s32, s32);
extern s32 func_002FBDF0(s32, s32, s32);
extern s32 func_002FC0F0(s32, s32, s32);
extern s32 func_002FC510(s32);
extern s32 func_002FCA90(s32, s32, s32);
extern s32 func_002FCFB0(s32, s32);
extern s32 func_002FD4E0(s32, s32);
extern s32 func_002FDA60(s32, s32, s32);

void func_002F9040(s32 arg0, s32 arg1) {
    s32 keep;

    if (arg1 == 0) {
        return;
    }
    keep = 1;
    while (keep != 0) {
        keep = 0;
        switch (func_002F9530(arg1)) {
        case 1:
            keep = func_002FDA60(arg0, arg1, 1);
            break;
        case 2:
            keep = func_002FDA60(arg0, arg1, 2);
            break;
        case 3:
            keep = func_002FD4E0(arg0, arg1);
            break;
        case 4:
            keep = func_002FCFB0(arg0, arg1);
            break;
        case 5:
            keep = func_002FCA90(arg0, arg1, 1);
            break;
        case 6:
            keep = func_002FCA90(arg0, arg1, 2);
            break;
        case 7:
            keep = func_002FC510(arg1);
            break;
        case 8:
            keep = func_002F9CE0(arg0, arg1, 1);
            break;
        case 9:
            keep = func_002F9CE0(arg0, arg1, 2);
            break;
        case 10:
            keep = func_002F9CE0(arg0, arg1, 3);
            break;
        case 11:
            keep = func_002F9CE0(arg0, arg1, 4);
            break;
        case 12:
            keep = func_002F9CE0(arg0, arg1, 5);
            break;
        case 13:
            keep = func_002FDA60(arg0, arg1, 4);
            break;
        case 14:
            keep = func_002FDA60(arg0, arg1, 5);
            break;
        case 15:
            keep = func_002FDA60(arg0, arg1, 6);
            break;
        case 16:
            keep = func_002FDA60(arg0, arg1, 7);
            break;
        case 17:
            keep = func_002FDA60(arg0, arg1, 8);
            break;
        case 18:
            keep = func_002FCA90(arg0, arg1, 3);
            break;
        case 19:
            keep = func_002FC0F0(arg0, arg1, 1);
            break;
        case 20:
            keep = func_002FC0F0(arg0, arg1, 2);
            break;
        case 21:
            keep = func_002FC0F0(arg0, arg1, 3);
            break;
        case 22:
            keep = func_002FBDF0(arg0, arg1, 4);
            break;
        case 23:
            keep = func_002FBDF0(arg0, arg1, 5);
            break;
        case 24:
            keep = func_002FBDF0(arg0, arg1, 1);
            break;
        case 25:
            keep = func_002FBDF0(arg0, arg1, 2);
            break;
        case 26:
            keep = func_002FBB60(arg0, arg1);
            break;
        case 27:
            keep = func_002FB860(arg0, arg1);
            break;
        case 28:
            keep = func_002FB5E0(arg1);
            break;
        case 29:
            keep = func_002FA0F0(arg0, arg1, 1);
            break;
        default:
            break;
        }
    }
}
