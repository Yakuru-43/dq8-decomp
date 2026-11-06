// range: 0x371780 0x371840
#include "common.h"

void func_001340C0(char *, char *);
s32 func_0025AB80(s32);
void func_0025B640(s32, s32 *);
s32 func_0025B760(s32);

void func_00371780(s32 arg0, s32 arg1, char *arg2) {
    char *node;

    if ((arg1 >= 0) && (arg1 < 6)) {
        node = *(char **)(arg0 + (arg1 * 4));
    } else {
        node = NULL;
    }
    if (node == NULL) {
        return;
    }
    func_0025B640(*(s16 *)(node + 2), (s32 *)(arg2 + 0x54));
    if (*(s32 *)(arg2 + 0x54) > 0) {
        *(s8 *)arg2 = 1;
    } else {
        *(s8 *)arg2 = 0;
    }
    *(s32 *)(arg2 + 4) = *(s32 *)(node + 8);
    *(f32 *)(arg2 + 8) = *(f32 *)(node + 0xC);
    *(s32 *)(arg2 + 0xC) = func_0025B760(*(s16 *)(node + 2));
    *(s32 *)(arg2 + 0x10) = func_0025AB80(*(s16 *)(node + 2));
    func_001340C0(arg2 + 0x14, node + 0x24);
}
