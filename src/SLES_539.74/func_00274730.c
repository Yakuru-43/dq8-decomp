// range: 0x274730 0x2747F0
#include "common.h"

/* file name + the two failed expressions */
extern char D_003C9EF0[];
extern char D_003C9F58[];
extern char D_003C9F70[];
extern u32 D_003E0D7C;

extern void func_0012D4D8(char *file, s32 line, char *expr);

typedef union Stamp {
    u32 word;
    u16 half[2];
} Stamp;

void func_00274730(Stamp *stamp, u32 value)
{
    u32 next;

    if (!(stamp->word) == 0) {
        func_0012D4D8(D_003C9EF0, 54, D_003C9F58);
    }
    if (!(value < 0x10000)) {
        func_0012D4D8(D_003C9EF0, 55, D_003C9F70);
    }
    next = D_003E0D7C + 1;
    D_003E0D7C = next;
    if (!(next < 0x10000)) {
        D_003E0D7C = 1;
    }
    next = D_003E0D7C;
    stamp->half[0] = value;
    stamp->half[1] = next;
}

