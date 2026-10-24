// range: 0x307BB0 0x307C80
#include "common.h"

typedef struct {
    char pad0[0x50];
    s32 bits[0x40]; /* +0x50 */
} EventFlags;

extern s32 func_00362650(s32 id);

static inline s32 IsValidFlag(s32 index) {
    if (index < 0 || index >= 0x800) {
        return 0;
    }
    return 1;
}

void func_00307BB0(EventFlags *flags, s32 id, s32 on) {
    s32 index;
    s32 mask;
    s32 word;
    s32 bit;

    index = func_00362650(id);
    if (IsValidFlag(index)) {
        mask = 1;
        word = index / 32;
        bit = index % 32;
        mask = mask << bit;
        if (on) {
            flags->bits[word] |= mask;
        } else {
            flags->bits[word] &= ~mask;
        }
    }
}
