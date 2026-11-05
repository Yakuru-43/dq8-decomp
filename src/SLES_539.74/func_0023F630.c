// range: 0x23F630 0x23F6C0
#include "common.h"

typedef union Value {
    s32 i;
    f32 f;
    char *s;
} Value;

typedef struct {
    s32 tag;
    Value value;
} Arg;

extern char *D_003E0B24;
extern char D_003C8790[];
extern void func_001340C0(char *, char *);

s32 func_0023F630(Arg *args, s32 kind) {
    s32 value;
    char *str = 0;

    if (args[0].tag == 1) {
        value = (s32)args[0].value.f;
    } else {
        value = args[0].value.i;
    }
    if (kind >= 2) {
        str = args[1].value.s;
    }
    *(s32 *)(D_003E0B24 + 0xC0) = value;
    if (str != 0) {
        func_001340C0(D_003E0B24 + 0xC4, str);
    } else {
        func_001340C0(D_003E0B24 + 0xC4, D_003C8790);
    }
    return 1;
}
