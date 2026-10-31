// range: 0x2D5440 0x2D55E0
#include "common.h"

extern u32 func_002D7830(s32, s32, s32);
extern u32 func_002D77E0(s32, s32, s32);
extern void func_002D7420(s32, s32, s32 *, s32 *);
extern void func_002E4DC0(char *, s16, s16);
extern void func_001FF370(char *, s32, s32);
extern void func_002F60F0(char *);

s32 func_002D5440(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp6C, sp68, sp64, sp60;
    u32 result;
    char *node;

    result = func_002D7830(arg0, arg1, 0);
    if (result != 0) {
        node = *(char **)(result + 4);
        if (node != NULL) {
            func_002D7420(arg0, arg1, &sp6C, &sp68);
            if (!(0.0f <= *(f32 *)(node + 0x174))) {
                func_002E4DC0(node, (s16)(sp6C + *(s16 *)result),
                              (s16)(sp68 + *(s16 *)(result + 2)));
            }
            *(s32 *)(node + 0x11C4) = -100;
            func_001FF370(node, arg2, 1);
            func_002F60F0(node);
            return 1;
        }
    }

    result = func_002D77E0(arg0, arg1, 0);
    if (result != 0) {
        node = *(char **)(result + 4);
        if (node != NULL) {
            func_002D7420(arg0, arg1, &sp64, &sp60);
            if (!(0.0f <= *(f32 *)(node + 0x174))) {
                func_002E4DC0(node, (s16)(sp64 + *(s16 *)result),
                              (s16)(sp60 + *(s16 *)(result + 2)));
            }
            *(s32 *)(node + 0x11C4) = -100;
            func_001FF370(node, arg2, 1);
            func_002F60F0(node);
            return 1;
        }
    }

    return 0;
}
