// range: 0x468C10 0x468D30
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

typedef struct BattleGlobal4 {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ char *field_04;
} BattleGlobal4;

union OutF {
    s128 q;
    f32 f[4];
};

extern char *D_0042186C __attribute__((section(".data")));
extern BattleGlobal4 *D_003E1BB0;

char *func_16D5B0(char *, s16);                      /* extern */
char *func_151B90(char *, s32);                      /* extern */
void func_1493E0(char *, f32 *);                     /* extern */

s32 func_00468C10(TagArg *self, s16 half) {
    char *obj;
    char *sub;
    s32 kind;
    char *p;
    char *r1;
    char *r2;
    TagArg *e;
    f32 v1f;
    f32 v2f;
    union OutF out;

    obj = D_0042186C;
    if (obj == 0) {
        return 0;
    }
    if (self[0].tag == 1) {
        kind = (s32)*(f32 *)&self[0].bits;
    } else {
        kind = self[0].bits;
    }
    switch (kind) {
    case 18:
        half = *(s16 *)(obj + 2);
        break;
    case 19:
        sub = *(char **)(obj + 0x48);
        half = *(s16 *)(sub + 6);
        break;
    }
    p = D_003E1BB0->field_04;
    if (p == 0) {
        return 0;
    }
    r1 = func_16D5B0(p, half);
    if (r1 == 0) {
        return 0;
    }
    r2 = func_151B90(r1, *(s32 *)(r1 + 0x468));
    if (r2 == 0) {
        return 0;
    }
    out.q = 0;
    func_1493E0(r2, out.f);
    e = self + 1;
    if (self[1].tag == 3) {
        *(f32 *)(e->bits + 4) = out.f[0];
    }
    v1f = out.f[1];
    e = self + 2;
    if (self[2].tag == 3) {
        *(f32 *)(e->bits + 4) = v1f;
    }
    v2f = out.f[2];
    if (self[3].tag == 3) {
        *(f32 *)(self[3].bits + 4) = v2f;
    }
    return 1;
}
