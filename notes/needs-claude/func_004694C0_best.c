// best attempt, 292 B vs 288: only the return-1 stub sharing differs (see func_004694C0.md)
// range: 0x4694C0 0x4695E0
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ char *field_04;
} BattleGlobal4;

union OutBuf {
    s128 q;
    f32 f[4];
};

extern char *D_0042186C __attribute__((section(".data")));
extern BattleGlobal4 *D_003E1BB0;

char *func_16D5B0(char *, s16);                      /* extern */
char *func_151B40(char *);                           /* extern */
void func_1493E0(char *, f32 *);                     /* extern */
f32 func_13D340(f32 *, f32 *);                       /* extern */

s32 func_004694C0(TagArg *self) {
    char *obj;
    char *r1;
    char *r2;
    char *p;
    s32 kind;
    f32 out;
    union OutBuf b1;
    union OutBuf b2;

    obj = D_0042186C;
    if (obj == 0 || D_003E1BB0->field_04 == 0) {
        return 0;
    }
    kind = (self[0].tag == 1) ? (s32)*(f32 *)&self[0].bits : self[0].bits;
    switch (kind) {
    case 10:
    case 11:
        r1 = func_16D5B0(D_003E1BB0->field_04, *(s16 *)(obj + 2));
        r2 = func_16D5B0(D_003E1BB0->field_04, *(s16 *)(*(char **)(obj + 0x48) + 6));
        if (r1 == 0) {
            return 1;
        }
        if (r2 == 0) {
            return 1;
        }
        p = func_151B40(r1);
        if (p != 0) {
            func_1493E0(p, b1.f);
        }
        p = func_151B40(r2);
        if (p != 0) {
            func_1493E0(p, b2.f);
        }
        out = func_13D340(b1.f, b2.f);
        if (self[1].tag == 3) {
            *(f32 *)(self[1].bits + 4) = out;
        }
        break;
    }
    return 1;
}
