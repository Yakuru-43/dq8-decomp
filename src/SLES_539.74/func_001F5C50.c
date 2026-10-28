// range: 0x1F5C50 0x1F5CD0
#include "common.h"

void func_001F8810(void *);
void func_001F8D50(void *);

void func_001F5C50(s32 arg0, void **arg1, s32 arg2) {
    s32 i;
    void *node;

    for (i = 0; i < arg2; i++) {
        node = arg1[i];
        if (node != 0) {
            if (*(s16 *)((char *)node + 0x32) != 0) {
                func_001F8810(node);
                func_001F8D50(node);
            }
        }
    }
}
