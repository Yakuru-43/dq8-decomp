// range: 0x4695E0 0x469940
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s32 field_04;
} BattleGlobal4;

typedef struct ScriptTable {
    /* 0x00 */ u8 pad0[0x90];
    /* 0x90 */ s32 count;
    /* 0x94 */ s32 args[1];
} ScriptTable;

f32 func_2CB310(s32, s16);                           /* extern */
f32 func_2CB3B0(s32, s16);                           /* extern */
void func_2CCB10(s32 *, s32, void *, f32 *, f32 *, s32, s32);  /* extern */
char *func_359CF0(M2C_UNK *, s32);                   /* extern */
u32 func_35E590(char *);                             /* extern */
f32 func_3611E0(void);                               /* extern */
f32 func_3611F0(void);                               /* extern */
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern char *D_0042186C __attribute__((section(".data")));
extern f32 D_42CCF0[] __attribute__((section(".data")));
extern f32 D_42CCF8[] __attribute__((section(".data")));
extern ScriptTable *D_003E1B8C;
extern BattleGlobal4 *D_003E1BB0;

s32 func_004695E0(TagArg *p) {
    TagArg *q;
    char *obj;
    ScriptTable *tab;
    s32 type;
    s32 n;
    s32 i;
    s32 src;
    s32 list[32];
    u8 buf[24];
    f32 outX;
    f32 outY;
    f32 res1;

    q = p + 1;
    if (p[0].tag == 1) {
        type = (s32)*(f32 *)&p[0].bits;
    } else {
        type = p[0].bits;
    }
    obj = D_0042186C;
    switch (type) {
    case 1:
        outX = D_42CCF0[0];
        outY = D_42CCF8[0];
        break;
    case 2:
        outX = D_42CCF0[1];
        outY = D_42CCF8[1];
        break;
    case 16:
        if (obj == 0) {
            break;
        }
        obj = func_359CF0(&D_421AD0, *(s16 *)(obj + 2));
        if (obj == 0) {
            break;
        }
        outX = D_42CCF0[func_35E590(obj)];
        outY = D_42CCF8[func_35E590(obj)];
        break;
    case 17:
        if (obj == 0) {
            break;
        }
        obj = func_359CF0(&D_421AD0, *(s16 *)(*(s32 *)(obj + 0x48) + 6));
        if (obj == 0) {
            break;
        }
        outX = D_42CCF0[func_35E590(obj)];
        outY = D_42CCF8[func_35E590(obj)];
        break;
    case 8:
        if (obj == 0) {
            break;
        }
        n = 0;
        list[n] = *(s16 *)(obj + 2);
        n = n + 1;
        src = *(s32 *)(obj + 0x64);
        if (src != 0) {
            i = 0;
            while (i < *(s16 *)(src + 4)) {
                list[n] = *(s16 *)(src + 8 + i * 2);
                n = n + 1;
                i = i + 1;
            }
        }
        func_2CCB10(list, n, buf, &outX, &outY, 0, 1);
        break;
    case 9:
        tab = D_003E1B8C;
        func_2CCB10(tab->args, tab->count, buf, &outX, &outY, 0, 1);
        break;
    case 12:
        if (obj == 0) {
            break;
        }
        outX = func_2CB3B0(D_003E1BB0->field_04, *(s16 *)(obj + 2));
        outY = func_2CB310(D_003E1BB0->field_04, *(s16 *)(obj + 2));
        break;
    case 13:
        if (obj == 0) {
            break;
        }
        outX = func_2CB3B0(D_003E1BB0->field_04,
                           *(s16 *)(*(s32 *)(obj + 0x48) + 6));
        outY = func_2CB310(D_003E1BB0->field_04,
                           *(s16 *)(*(s32 *)(obj + 0x48) + 6));
        break;
    case 3:
        res1 = func_3611E0();
        if (q[0].tag == 3) {
            *(f32 *)((char *)q[0].bits + 4) = res1;
        }
        res1 = func_3611F0();
        if (q[1].tag == 3) {
            *(f32 *)((char *)q[1].bits + 4) = res1;
        }
        q = q + 2;
        break;
    }
    if (q[0].tag == 3) {
        *(f32 *)((char *)q[0].bits + 4) = outX;
    }
    if (q[1].tag == 3) {
        *(f32 *)((char *)q[1].bits + 4) = outY;
    }
    return 1;
}
