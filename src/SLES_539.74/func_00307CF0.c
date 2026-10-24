// range: 0x307CF0 0x307D90
#include "common.h"

typedef struct {
    char pad0[0x350];
    s32 bits[4]; /* +0x350 */
} ItemFlags;

extern char D_004392D0[];
extern s32 func_002AF290(void *table, s32 id);

void func_00307CF0(ItemFlags *flags, s32 id, s32 on) {
    s32 index;
    s32 mask;
    s32 word;
    s32 bit;

    index = func_002AF290(D_004392D0, id);
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
