// range: 0x469100 0x469270
#include "common.h"

typedef struct LinkTarget {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 value;
} LinkTarget;

typedef struct CondPair {
    /* 0x00 */ s32 tag;
    /* 0x04 */ LinkTarget *link;
} CondPair;

typedef struct Node469100 {
    /* 0x00 */ CondPair pair[3];
} Node469100;

s32 func_2B02C0();                     /* extern */
s32 func_2CD2D0();                      /* extern */
char *func_359CF0(M2C_UNK *, s32);      /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern M2C_UNK D_42EAA0 __attribute__((section(".data")));
extern char *D_0042186C __attribute__((section(".data")));

s32 func_00469100(Node469100 *n) {
    char *obj;
    char *work;
    char *temp;
    s32 val;

    obj = D_0042186C;
    if (obj == 0) {
        return 0;
    }
    temp = func_359CF0(&D_421AD0, *(s16 *)(obj + 2));
    work = (char *)func_2CD2D0(*(s32 *)temp);
    if (*(s16 *)(obj + 0xC) == 0x4B || *(s16 *)(obj + 0xC) == 0x4C ||
        (u32)(*(s16 *)(obj + 0xC) - 0x1F) < 2) {
        func_2B02C0(&D_42EAA0, work);
    }
    if (work == 0) {
        if (n->pair[0].tag == 3) {
            n->pair[0].link->value = -1;
        }
        if (n->pair[1].tag == 3) {
            n->pair[1].link->value = -1;
        }
        if (n->pair[2].tag == 3) {
            n->pair[2].link->value = -1;
        }
    } else {
        val = func_2CD2D0(*(s32 *)work);
        if (n->pair[0].tag == 3) {
            n->pair[0].link->value = *(s16 *)(obj + 2);
        }
        if (n->pair[1].tag == 3) {
            n->pair[1].link->value = val;
        }
        if (n->pair[2].tag == 3) {
            n->pair[2].link->value = *(s16 *)(obj + 0xC);
        }
    }
    return 1;
}
