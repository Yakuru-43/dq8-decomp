// range: 0x1F7090 0x1F70D0
#include "common.h"

void func_001F7090(char *arg0) {
    s32 count = *(s32 *)(arg0 + 0x4E4);
    char **base = *(char ***)(arg0 + 0x4E8);
    s32 i = 0;

    while (i < count) {
        char *node = base[i];
        if (node != NULL) {
            *(char **)(node + 0x34) = arg0;
            *(s32 *)(node + 0x38) = 0;
        }
        i++;
    }
}
