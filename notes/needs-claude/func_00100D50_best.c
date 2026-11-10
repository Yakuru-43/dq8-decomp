// range: 0x100D50 0x100DB0
#include "common.h"

struct BootCb {
    s32 next;
    void (*fn)(s32, s32);
    s32 arg;
};

extern char D_003E1D00[]; /* BootCb *head, kept absolute in the object */

void func_00100D50(void) {
    struct BootCb *node;

    node = *(struct BootCb **)D_003E1D00;
    do {
        *(struct BootCb **)D_003E1D00 = (struct BootCb *)node->next;
        node->fn(node->arg, -1);
        node = *(struct BootCb **)D_003E1D00;
        if (node == 0) {
            break;
        }
    } while (node != 0);
}
