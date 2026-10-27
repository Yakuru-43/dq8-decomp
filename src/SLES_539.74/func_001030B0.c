// range: 0x1030B0 0x103150
// Constructing helper of the D_003DD7C0/FC/D8 class family (sibling of
// func_00104060): stores the object vptr at +4, the vbtable vptr and the
// virtual-base delta (+0x48) through the table pointer at +0, builds the
// sub-object at +8 when the flag is set, and frees the object when it is
// positive.  Returns the object.
#include "common.h"

extern M2C_UNK D_003DD7C0 __attribute__((section(".data")));
extern M2C_UNK D_003DD7CC __attribute__((section(".data")));
extern M2C_UNK D_003DD7A8 __attribute__((section(".data")));

extern void func_00102A50(void *obj, s16 n);
extern void func_001007A0(void *node);

struct Node {
    u32 handle;     /* vbtable pointer, used as an integer */
    u32 vtbl_04;
    u32 vtbl_08;
};

void *func_001030B0(void *obj, s32 n) {
    struct Node *node = obj;
    u32 h1;
    u32 h2;
    void *sub;

    if (obj != 0) {
        sub = (char *)obj + 8;
        node->vtbl_04 = (u32)&D_003DD7C0;
        h1 = node->handle;
        *(u32 *)h1 = (u32)&D_003DD7CC;
        h2 = node->handle;
        *(u32 *)(h2 + 0x48) = (u32)sub - h2;
        if (n != 0) {
            if (sub != 0) {
                node->vtbl_08 = (u32)&D_003DD7A8;
                func_00102A50(sub, 0);
            }
        }
        if ((s16)n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
