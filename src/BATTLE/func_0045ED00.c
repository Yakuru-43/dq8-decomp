// range: 0x45ED00 0x45EDC0
#include "common.h"

typedef struct {
    char pad0[0x14];
    s32 unk14;
} S_item;

extern int func_0045EDE0(void *arg0);
extern S_item *func_0045EDD0(void *arg0, s32 index);
extern s32 func_0045EDC0(S_item *arg0);
extern void func_157930(s32, s32);

void func_0045ED00(void *arg0, s32 arg1) {
    S_item *item;
    s32 v;
    s32 count;
    s32 i;

    if (arg0 == 0) {
        return;
    }
    count = func_0045EDE0(arg0);
    for (i = 0; i < count; i++) {
        item = func_0045EDD0(arg0, i);
        if (item == 0) {
            continue;
        }
        v = func_0045EDC0(item);
        if (arg1 == 0) {
            func_157930(v, 1);
        } else if (arg1 == 1) {
            func_157930(v, 0);
        }
    }
}
