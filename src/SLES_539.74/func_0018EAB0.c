// range: 0x18EAB0 0x18EB40
#include "common.h"

char *func_001340C0(char *, char *);

typedef struct Rec {
    u8 pad_00[0x10];   /* 0x00 */
    char *name_10;     /* 0x10 */
    u8 pad_14[8];      /* 0x14 */
} Rec;

Rec *func_0018F3F0(s32);

s32 func_0018EAB0(s32 arg0, char *dst, s32 arg2) {
    Rec *a;
    Rec *b;
    char *nb;
    char *na;

    a = func_0018F3F0(arg0);
    if (a == 0) {
        return 0;
    }
    b = func_0018F3F0(arg2);
    nb = 0;
    if (b != 0) {
        nb = b->name_10;
    }
    na = a->name_10;
    if (na == 0) {
        return 0;
    }
    if (nb == na) {
        return 2;
    }
    func_001340C0(dst, na);
    func_001340C0(dst + 0x80, a->name_10);
    return 1;
}
