// range: 0x295D70 0x295DD0
#include "common.h"

struct Owner {
    char pad_0[0x58C];
    void *sub;
};

extern s32 func_002912B0(struct Owner *a0, void *a1);
extern s32 func_00296F70(void *a0);
extern s32 func_00296BB0(struct Owner *a0);

s32 func_00295D70(struct Owner *owner) {
    s32 first;
    s32 second;

    first = func_002912B0(owner, owner->sub);
    second = func_00296F70(owner->sub);
    if (second < first) {
        func_00296BB0(owner);
        return 1;
    }
    return 0;
}
