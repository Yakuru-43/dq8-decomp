// best attempt (attempt 1, CLASS structural score=94, 364 vs 348 bytes):
// shared locals across the two branches; variant 3 with block-local copies
// (func_0013F0E0_best_v3.c) is worse (score=96). Needs
// // flags: -flag divbyzerocheck (line 2) for the div guard.
// range: 0x13F0E0 0x13F240
// flags: -flag divbyzerocheck
#include "common.h"

void func_0013F0E0(char *arg0) {
    char *wp;
    char *base;
    s32 n1;
    s32 n2;
    s32 n3;

    if (M2C_FIELD(arg0, s32 *, 0x114) == 0) {
        wp = M2C_FIELD(arg0, char **, 0xF4);
        base = M2C_FIELD(arg0, char **, 0xF8);
        n1 = (wp - base) / 16 - 1;
        n2 = (wp - M2C_FIELD(arg0, char **, 0xFC)) / 16 - 1;
        n3 = (wp - M2C_FIELD(arg0, char **, 0x100)) / 16 - 1;
        if (n1 > 0 && n2 > 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x104), s32 *, 0) = n1 | 0x10000000;
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x108), s32 *, 0) = n2 | 0x50000000;
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x100), s32 *, 0) = n3 | 0x8000;
        } else {
            M2C_FIELD(arg0, char **, 0xF4) = base;
        }
    } else {
        wp = M2C_FIELD(arg0, char **, 0xF4);
        base = M2C_FIELD(arg0, char **, 0xF8);
        n1 = (wp - base) / 16 - 1;
        n2 = (wp - M2C_FIELD(arg0, char **, 0xFC)) / 16 - 1;
        n3 = (wp - M2C_FIELD(arg0, char **, 0x100)) / 16 - 1;
        if (n1 > 0 && n2 > 0) {
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x104), s32 *, 0) = n1 | 0x10000000;
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x108), s32 *, 0) = n2 | 0x50000000;
            M2C_FIELD(M2C_FIELD(arg0, char **, 0x100), s32 *, 0) =
                (n3 / M2C_FIELD(arg0, s32 *, 0x118)) | 0x8000;
        } else {
            M2C_FIELD(arg0, char **, 0xF4) = base;
        }
    }
}
