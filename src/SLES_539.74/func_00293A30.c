// range: 0x293A30 0x293AA0
#include "common.h"

struct Owner {
    char pad_0[0x58C];
    s32 sub;
    s32 list[1];
};

extern s32 func_00292960(struct Owner *owner);
extern s32 func_002946D0(struct Owner *owner);

s32 func_00293A30(struct Owner *owner) {
    s32 sub;
    s32 saved;

    sub = owner->sub;
    saved = *(s32 *)(sub + 0xE8);
    *(s32 *)(sub + 0xE8) = 2;
    func_00292960(owner);
    sub = owner->sub;
    *(s32 *)(sub + 0xE8) = saved;
    sub = owner->sub;
    if (owner->list[*(s16 *)(sub + 0x10)] == 8) {
        return func_002946D0(owner);
    }
    return 0;
}
