// range: 0x151F40 0x152040
#include "common.h"

void func_0014ACB0(char *);
char *func_00153920(s32, s32);

void func_00151F40(char *arg0, s32 arg1) {
    s32 i;
    char *p;

    *(s32 *)(arg0 + 0x100) = 0;
    *(s32 *)(arg0 + 4) = 0;

    if (*(s32 *)(arg0 + 0x110) != 0) {
        if (*(s32 *)(arg0 + 0) != 0) {
            for (i = 0; i < *(s32 *)(arg0 + 0x10C); i++) {
                p = func_00153920(*(s32 *)(arg0 + 0x104),
                    *(s32 *)(*(s32 *)(arg0 + 0x110) + i * 4));
                if (p != 0) {
                    if (*(s8 *)(p + 0x28) != 0) {
                        *(s32 *)(p + 4) = 0;
                    }
                }
            }
        }
    }

    *(s32 *)(arg0 + 4) = arg1;

    if (*(s32 *)(arg0 + 0x110) != 0) {
        if (*(s32 *)(arg0 + 0) != 0) {
            for (i = 0; i < *(s32 *)(arg0 + 0x10C); i++) {
                p = func_00153920(*(s32 *)(arg0 + 0x104),
                    *(s32 *)(*(s32 *)(arg0 + 0x110) + i * 4));
                if (p != 0) {
                    *(s8 *)(p + 0x28) = 1;
                    *(s32 *)(p + 4) = arg1;
                    func_0014ACB0(p);
                }
            }
        }
    }
}
