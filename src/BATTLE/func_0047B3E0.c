// range: 0x47B3E0 0x47B470
#include "common.h"

extern s32 func_133F78(char *, char *);

extern char D_00484A00[]; /* "ON" */

extern s32 *D_003E1BD0 __attribute__((section(".sdata")));

typedef struct {
    s32 type;
    s32 unk4;
    char pad8[0x8];
    s32 sound;
    char pad14[0x3C];
    char *name;
} S_entry;

s32 func_0047B3E0(s32 arg0, s32 arg1, S_entry *arg2) {
    if (arg2->name == 0) {
        return 1;
    }
    if (func_133F78(arg2->name, D_00484A00) == 0) {
        if (D_003E1BD0[arg2->sound + 0xC34] != 1) {
            return 2;
        }
    } else {
        if (D_003E1BD0[arg2->sound + 0xC34] != 0) {
            return 2;
        }
    }
    return 0;
}
