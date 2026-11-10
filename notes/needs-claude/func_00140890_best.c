// range: 0x140890 0x1409C0
#include "common.h"

typedef struct Node {
    /* 00 */ char pad_0[4];
    /* 04 */ s32 idx;
    /* 08 */ char pad_8[0x1C];
    /* 24 */ struct Node *next;
} Node;

typedef struct {
    /* 0000 */ char pad_0[0x3B94];
    /* 3B94 */ char *name;
    /* 3B98 */ char pad_3B98[4];
    /* 3B9C */ s32 loaded;
    /* 3BA0 */ char pad_3BA0[0xC];
    /* 3BAC */ s32 count;
    /* 3BB0 */ s32 *idx0;
    /* 3BB4 */ s32 *counts;
    /* 3BB8 */ s32 *sizes;
    /* 3BBC */ Node **lists;
    /* 3BC0 */ char pad_3BC0[4];
    /* 3BC4 */ s32 listCount;
} Obj;

s32 func_0014E130(s32, s32);                    /* extern */

void func_00140890(Obj *o) {
    s32 i;
    s32 *p;
    char *name;
    s32 v;
    s32 n;
    Node *node;
    s32 val;

    name = o->name;
    if (name == 0) {
        return;
    }
    p = o->sizes;
    for (i = 0; i < o->count; i++) {
        v = *p;
        p++;
        if (v > 0) {
            o->idx0[i] = func_0014E130((s32)name, (v / 4) + 1);
            o->counts[i] = o->idx0[i];
        }
    }
    for (n = o->listCount; n >= 0; n--) {
        node = o->lists[n];
        if (node != 0) {
            while (node != 0) {
                val = o->counts[node->idx];
                o->counts[node->idx] = val + 4;
                *(s32 *)val = (s32)node;
                node = node->next;
            }
        }
    }
    o->loaded = 1;
}
