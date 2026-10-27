// range: 0x1AC020 0x1AC0F0
#include "common.h"

void func_0014ACB0(char *);
char *func_00151B40(char *);

s32 func_001AC020(char *arg0, s32 arg1, char *arg2) {
    char *node;
    s32 type;
    char *ptr;
    char *result;

    if (arg1 < 0 || arg1 >= 0x20) {
        return 0;
    }

    node = arg0 + (arg1 * 0x10);
    type = *(s32 *)node;

    switch (type) {
    case 0:
        ptr = *(char **)(node + 0xC);
        if (ptr == 0) {
            return 0;
        }
        result = func_00151B40(ptr);
        if (result == 0) {
            return 0;
        }
        *(f32 *)(result + 0x90) = *(f32 *)(arg2 + 0);
        *(f32 *)(result + 0x94) = *(f32 *)(arg2 + 4);
        *(f32 *)(result + 0x98) = *(f32 *)(arg2 + 8);
        func_0014ACB0(result);
        return 1;
    case 3:
        ptr = *(char **)(node + 0xC);
        if (ptr == 0) {
            return 0;
        }
        *(f32 *)(ptr + 0x90) = *(f32 *)(arg2 + 0);
        *(f32 *)(ptr + 0x94) = *(f32 *)(arg2 + 4);
        *(f32 *)(ptr + 0x98) = *(f32 *)(arg2 + 8);
        func_0014ACB0(ptr);
        return 1;
    default:
        return 0;
    }
}
