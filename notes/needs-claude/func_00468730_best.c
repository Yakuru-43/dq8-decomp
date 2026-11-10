// range: 0x468730 0x4689C0
#include "common.h"

typedef struct TagArg {
    /* 0x00 */ s32 tag;
    /* 0x04 */ s32 bits;
} TagArg;

s32 func_359620(M2C_UNK *, u32, char **, s32, s32, s32, s32, s32, s32, s32);
char *func_359CF0(M2C_UNK *, s32);
u32 func_35E590(char *);
extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern char *D_0042186C __attribute__((section(".data")));

s32 func_00468730(TagArg *self, s32 mode) {
    char *obj;
    char *sub;
    char *ent;
    char *r;
    TagArg *e;
    s32 kind;
    s32 div;
    s32 cnt;
    s32 i;
    char *buf[0x20];
    f32 val;
    f32 q;

    if (self[0].tag == 1) {
        kind = (s32)*(f32 *)&self[0].bits;
    } else {
        kind = self[0].bits;
    }
    e = self + 1;
    if (self[1].tag == 0) {
        val = (f32)e->bits;
    } else {
        val = *(f32 *)&e->bits;
    }
    div = 0;
    if (mode == 3) {
        div = (self[2].tag == 1) ? (s32)*(f32 *)&self[2].bits : self[2].bits;
    }
    obj = D_0042186C;
    switch (kind) {
    case 12:
        if (obj != 0) {
            r = func_359CF0(&D_421AD0, *(s16 *)(obj + 2));
            if (r != 0) {
                *(f32 *)(r + 0x538) = val;
                if (div > 0) {
                    *(f32 *)(r + 0x53C) = val / (f32)div;
                } else {
                    *(f32 *)(r + 0x53C) = 1.0f;
                }
            }
        }
        break;
    case 16:
        if (obj != 0) {
            r = func_359CF0(&D_421AD0, *(s16 *)(obj + 2));
            cnt = func_359620(&D_421AD0, func_35E590(r), buf, 0x20,
                              1, 1, 0, -1, 1, 1);
            q = val / (f32)div;
            for (i = 0; i < cnt; i++) {
                ent = buf[i];
                *(f32 *)(ent + 0x538) = val;
                if (div > 0) {
                    *(f32 *)(ent + 0x53C) = q;
                } else {
                    *(f32 *)(ent + 0x53C) = 1.0f;
                }
            }
        }
        break;
    case 34:
        if (obj != 0) {
            if (*(s16 *)(obj + 0x44) > 0) {
                sub = *(char **)(obj + 0x48);
                r = func_359CF0(&D_421AD0, *(s16 *)(sub + 6));
                cnt = func_359620(&D_421AD0, func_35E590(r) == 0, buf, 0x20,
                                  1, 1, 0, -1, 1, 1);
                q = val / (f32)div;
                for (i = 0; i < cnt; i++) {
                    ent = buf[i];
                    *(f32 *)(ent + 0x538) = val;
                    if (div > 0) {
                        *(f32 *)(ent + 0x53C) = q;
                    } else {
                        *(f32 *)(ent + 0x53C) = 1.0f;
                    }
                }
            }
        }
        break;
    }
    return 1;
}
