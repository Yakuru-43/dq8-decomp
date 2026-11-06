// range: 0x47AAF0 0x47ABA0
#include "common.h"

extern s32 func_133F78(char *, char *);

extern char D_00484A00[]; /* "ON" */
extern char D_00484A08[]; /* "OFF" */

typedef struct {
    char pad0[0x238];
    s32 onOff;
    s32 sound;
    s32 sound2;
} S_globals;

extern S_globals *D_003E1B8C __attribute__((section(".sdata")));

typedef struct {
    s32 type;
    s32 unk4;
    char pad8[0x8];
    s32 sound;
    s32 sound2;
    char pad18[0x38];
    char *name;
} S_entry;

s32 func_0047AAF0(s32 arg0, s32 arg1, S_entry *arg2) {
    S_entry *s = arg2;

    if (s->name == 0) {
        return 1;
    }
    if (func_133F78(s->name, D_00484A00) == 0) {
        D_003E1B8C->onOff = 1;
    }
    if (func_133F78(s->name, D_00484A08) == 0) {
        D_003E1B8C->onOff = 0;
    }
    D_003E1B8C->sound = s->sound;
    if (s->unk4 <= 1) {
        D_003E1B8C->sound2 = 0;
    } else {
        D_003E1B8C->sound2 = s->sound2;
    }
    return 0;
}
