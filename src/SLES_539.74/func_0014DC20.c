// range: 0x14DC20 0x14DC80
#include "common.h"

extern void func_0014D810(void);

void func_0014DC20(char *arg0) {
    char *node;
    char *next;

    func_0014D810();
    node = *(char **)(arg0 + 0x4C);
    *(char **)(arg0 + 0x4C) = NULL;
    while (node != NULL) {
        func_0014DC20(node);
        *(s32 *)(node + 0x40) = 0;
        *(s32 *)(node + 0x44) = 0;
        next = *(char **)(node + 0x48);
        *(char **)(node + 0x48) = NULL;
        node = next;
    }
}
