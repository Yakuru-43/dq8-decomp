// range: 0x1036A0 0x103740
// Constructing helper of the D_003DD6C0/CC/D8 class family (twin of
// func_00103600): stores the object vptr at +0x10, the vbtable vptr and the
// virtual-base delta (+0x48) through the table pointer at +0, builds the
// sub-object at +0x18 when the flag is set, and frees the object when it is
// positive.  Returns the object.
#include "common.h"

extern M2C_UNK D_003DD6C0 __attribute__((section(".data")));
extern M2C_UNK D_003DD6CC __attribute__((section(".data")));
extern M2C_UNK D_003DD6D8 __attribute__((section(".data")));

extern void func_00102A50(void *obj, s16 n);
extern void func_001007A0(void *node);

struct Node {
    u32 handle;     /* vbtable pointer, used as an integer */
    u32 gap_04[3];
    u32 vtbl_10;
    u32 gap_14[1];
    u32 vtbl_18;
};

void *func_001036A0(void *obj, s32 n) {
    struct Node *node = obj;
    u32 h1;
    u32 h2;
    void *sub;

    if (obj != 0) {
        sub = (char *)obj + 0x18;
        node->vtbl_10 = (u32)&D_003DD6C0;
        h1 = node->handle;
        *(u32 *)h1 = (u32)&D_003DD6CC;
        h2 = node->handle;
        *(u32 *)(h2 + 0x48) = (u32)sub - h2;
        if (n != 0) {
            if (sub != 0) {
                node->vtbl_18 = (u32)&D_003DD6D8;
                func_00102A50(sub, 0);
            }
        }
        if ((s16)n > 0) {
            func_001007A0(obj);
        }
    }
    return obj;
}
