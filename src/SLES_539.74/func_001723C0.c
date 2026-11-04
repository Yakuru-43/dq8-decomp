// range: 0x1723C0 0x172520
#include "common.h"

extern char D_003C2A68[] __attribute__((section(".data"))); /* "KeyOn" */
extern s32 func_00133F78(char *, char *);
extern s32 func_00133BE0(char *, char *);

struct KeyEnt {
    s32 name;
    s32 unk4;
    s32 unk8;
};

struct KeyBank {
    u8 pad[0x20];
    s32 count1;
    char **names;
    s32 unk28;
    s32 *vals;
    s32 count2;
    struct KeyEnt *ents;
};

s32 func_001723C0(struct KeyBank *bank, char *name, s32 *out, s32 *out2) {
    s32 off;
    s32 j;
    s32 i;
    s32 k;
    s8 c;

    if (name == 0 || *name == 0) {
        return 0;
    }
    if (func_00133F78(name, D_003C2A68) == 0) {
        return 1;
    }
    *out2 = -1;
    i = 0;
    while (i < bank->count1) {
        off = i << 2;
        if (func_00133BE0(*(char **)((char *)bank->names + off), name) == 0) {
            *out = i;
            *out2 = *(s32 *)((char *)bank->vals + off);
            return 2;
        }
        i++;
    }
    j = 0;
    while (j < bank->count2) {
        if (bank->ents[j].name != 0) {
            if (func_00133BE0((char *)bank->ents[j].name, name) == 0) {
                *out = j;
                return 3;
            }
        }
        j++;
    }
    k = 0;
    while (name[k] != 0) {
        c = name[k];
        if (c == '.') {
            return 0;
        }
        k++;
    }
    return 1;
}
