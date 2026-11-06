// range: 0x47B740 0x47B830
#include "common.h"

extern s32 func_133F78(char *, char *);

extern char D_00484730[]; /* "POS_TGT" */
extern char D_00484810[]; /* "POS_TGT_F" */
extern char D_00484A40[]; /* "POS_TGT_CTR" */
extern char D_004847B8[]; /* "POS_TGT_CTR_F" */

extern s32 *D_003E1BD0 __attribute__((section(".sdata")));

typedef struct {
    s32 type;
    s32 unk4;
    char pad8[0x8];
    s32 sound;
    char pad14[0x3C];
    char *name;
} S_entry;

s32 func_0047B740(s32 arg0, s32 arg1, S_entry *arg2) {
    s32 sound;

    if (arg2->name == 0) {
        return 1;
    }
    sound = arg2->sound;
    if (func_133F78(arg2->name, D_00484730) == 0) {
        D_003E1BD0[sound + 0xC16] = 0;
    }
    if (func_133F78(arg2->name, D_00484810) == 0) {
        D_003E1BD0[sound + 0xC16] = 1;
    }
    if (func_133F78(arg2->name, D_00484A40) == 0) {
        D_003E1BD0[sound + 0xC16] = 2;
    }
    if (func_133F78(arg2->name, D_004847B8) == 0) {
        D_003E1BD0[sound + 0xC16] = 3;
    }
    return 0;
}
