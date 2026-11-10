// best draft for func_00212850 (needs-claude) — compiled clean, score=202 structural
// range: 0x212850 0x212BA0
#include "common.h"

extern char *D_003E0908;
extern char *D_003E0928;
extern char *D_003E0944;
extern s16 D_003E092C;
extern char D_003C7CC0[];
extern char D_003E0920;

char *func_0015F490(void);
char *func_0015F450(void);
char *func_0015AEF0(char *, char *, s32);
void func_001419A0(char *, s32, f32);
s32 func_00145450(char *);
s32 func_00145440(char *);
char *func_00141BF0(char *);
void func_00141B00(char *);
s32 func_00133F78(char *, char *);
s32 func_001814D0(void);
char *func_00191EB0(s32);
char *func_003089E0(char *, s32);
void func_002112C0(char *);
void func_0013E410(char *, s32);
char *func_00211AC0(char *);
s32 func_00212D40(char *);
void func_00212D90(char *, s32);
void func_00214740(void);
void func_002179D0(char *, s32, s32, f32, f32);
void func_00212BA0(char *, s32, s32);
void func_00217100(s32 *, s32 *, s32, s32);
s32 func_001FFC30(s32);
void func_003731B0(s32, s32, s32, s32, s32);
void func_0022ABB0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_0022ADF0(char *, s32, s32, s32, s32, s32, s32, s32);
void func_0022B020(char *, char *, s32, s32, s32, s32, s32, s32, s64, s64,
                  s64, s64);

void func_00212850(void) {
    char *v4;
    char *v5;
    char *h1;
    s32 a2v;
    s32 a3v;
    char *msg;
    char *item;
    char *name;
    char *entry;
    s32 i;
    s32 off;
    s32 t1;
    char *t2;
    char *found;
    char *obj;
    s32 v0;
    s32 v1;
    s32 d40;
    s32 outB;
    s32 outA;
    s32 r;

    func_0015F490();
    v5 = v4 = func_0015F450();
    h1 = func_0015AEF0(v5, D_003C7CC0, -1);
    if (h1 != 0) {
        func_001419A0(v4, M2C_FIELD(h1, s16 *, 0), 1.0f);
        a2v = func_00145450(v4);
        a3v = func_00145440(v4);
        func_0022ABB0(0, 0, a2v, a3v, 0, 0, 0,
                      M2C_FIELD(D_003E0908, s32 *, 0x414));
        func_0022ADF0(h1, 0, 0, 0, 0, 0x200, 0x1C0,
                      M2C_FIELD(D_003E0908, s32 *, 0x414));
    }
    msg = func_00211AC0(D_003E0908 + 0x430);
    item = 0;
    entry = msg;
    if (msg != 0) {
        item = (char *)M2C_FIELD(msg, s32 *, 0);
        for (i = 0; i < D_003E092C; i++) {
            off = i * 0xA0;
            if (func_00133F78(D_003E0928 + off + 0x68, msg + 4) == 0) {
                found = D_003E0928 + off;
                if (M2C_FIELD(found, s32 *, 0x88) == 3) {
                    t1 = func_001814D0();
                    t2 = func_00191EB0(t1);
                    if (func_003089E0(t2, M2C_FIELD(found, s32 *, 0x8C)) != 0) {
                        found = D_003E0928 + off;
                        if (M2C_FIELD(found, u8 *, 4) != 0) {
                            entry = found;
                            item = func_0015AEF0(v5, found + 4, -1);
                        }
                    }
                }
            }
        }
    }
    if (msg != 0 && item != 0) {
        func_001419A0(v4, M2C_FIELD(item, s16 *, 0), 1.0f);
        obj = func_00141BF0(v4);
        func_002112C0(obj);
        func_0013E410(obj, 3);
        func_0022B020(obj, item, M2C_FIELD(msg, s16 *, 0x24),
                      M2C_FIELD(msg, s16 *, 0x26), M2C_FIELD(msg, s16 *, 0x28) - 1,
                      M2C_FIELD(msg, s16 *, 0x2A) - 1, M2C_FIELD(msg, s16 *, 0x24),
                      M2C_FIELD(msg, s16 *, 0x26),
                      (s64)(M2C_FIELD(msg, s16 *, 0x28) - 1),
                      (s64)(M2C_FIELD(msg, s16 *, 0x2A) - 1), (s64)0x80,
                      (s64)M2C_FIELD(D_003E0908, s32 *, 0x414));
        func_00141B00(v4);
    }
    if (msg != 0 && M2C_FIELD(D_003E0944, u8 *, 0x73) != 0) {
        func_00212D90(entry + 4, M2C_FIELD(D_003E0908, s32 *, 0x414));
    }
    func_00214740();
    found = D_003E0908;
    d40 = func_00212D40(found);
    func_002179D0(D_003E0908 + 0x62C, d40, M2C_FIELD(found, s32 *, 0x418), 2.0f,
                  3.0f);
    v1 = (s32)M2C_FIELD(D_003E0908, f32 *, 0x64C);
    v0 = (s32)M2C_FIELD(D_003E0908, f32 *, 0x650);
    func_00212BA0(&D_003E0920, M2C_FIELD(D_003E0908, s32 *, 0x420), 0);
    if (M2C_FIELD(D_003E0908, s32 *, 0x414) >= 0x80) {
        func_00217100(&outA, &outB, v1, v0);
        r = func_001FFC30((M2C_FIELD(D_003E0944, u8 *, 0x73) == 0) + 0xBC2);
        func_003731B0(r, outA, outB, 1, 1);
    }
}
