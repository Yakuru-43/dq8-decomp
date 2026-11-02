// range: 0x468610 0x468730
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct Node468610 {
    /* 0x00 */ TagArg a[2];
} Node468610;

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 field_04;
} BattleGlobal4;

s32 func_357380(M2C_UNK *, s32, u32, s32);            /* extern */
char *func_359CF0(M2C_UNK *, s32);                     /* extern */
u32 func_35E590(char *);                                /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern char *D_0042186C __attribute__((section(".data")));
extern BattleGlobal4 *D_003E1BB0;

s32 func_00468610(Node468610 *n) {
    TagArg *p;
    char *obj;
    s32 kind;
    s32 glb;
    s32 val;

    glb = D_003E1BB0->field_04;
    p = n->a;
    if (p[0].tag == 1) {
        kind = (s32)*(f32 *)&p[0].bits;
    } else {
        kind = p[0].bits;
    }
    if (p[1].tag == 1) {
        val = (s32)*(f32 *)&p[1].bits;
    } else {
        val = p[1].bits;
    }
    obj = D_0042186C;
    switch (kind) {
    case 33:
        if (obj != 0) {
            func_357380(&D_421AD0, glb,
                        func_35E590(func_359CF0(
                            &D_421AD0, *(s16 *)(obj + 2))) == 0,
                        val);
        }
        break;
    case 34:
        if (obj != 0) {
            func_357380(&D_421AD0, glb,
                        func_35E590(func_359CF0(
                            &D_421AD0,
                            *(s16 *)(*(s32 *)(obj + 0x48) + 6))) == 0,
                        val);
        }
        break;
    }
    return 1;
}
