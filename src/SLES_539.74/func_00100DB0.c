// range: 0x100DB0 0x100DE0
#include "common.h"

struct BootCb {
    s32 next;
    void (*fn)(s32, s32);
    s32 arg;
};

extern char D_003E1D00[]; /* BootCb *head, kept absolute in the object */

s32 func_00100DB0(s32 arg, void (*fn)(s32, s32), struct BootCb *node) {
    node->next = *(s32 *)D_003E1D00;
    node->fn = fn;
    node->arg = arg;
    *(struct BootCb **)D_003E1D00 = node;
    return arg;
}
