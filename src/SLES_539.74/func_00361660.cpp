// range: 0x361660 0x3617B0
// Builds a runtime record from a template: copies the ids and remembers the
// template pointer, looks up the stage entry D_0042CDB4 + idx * 0x50 with the
// record's own index field, clears the live-state fields and zeroes the
// 12-byte block at +0x78.
#include "common.h"

extern "C" {

typedef struct {
    /* 000 */ s32 f00;
    /* 004 */ char pad04[0x0C - 0x04];
    /* 00C */ s16 f0C;
    /* 00E */ char pad0E[0xA6 - 0x0E];
    /* 0A6 */ s16 fA6;
    /* 0A8 */ char padA8[0x160 - 0xA8];
    /* 160 */ s32 f160[2];
} Src;

typedef struct {
    /* 000 */ u16 f00;
    /* 002 */ u16 f02;
    /* 004 */ u16 f04;
    /* 006 */ char pad06[2];
    /* 008 */ Src *f08;
    /* 00C */ s16 fC;
    /* 00E */ u16 fE;
    /* 010 */ char pad10[4];
    /* 014 */ s32 f14;
    /* 018 */ u8 f18;
    /* 019 */ u8 f19;
    /* 01A */ u8 f1A;
    /* 01B */ u8 f1B;
    /* 01C */ s32 f1C;
    /* 020 */ u16 f20;
    /* 022 */ s16 f22;
    /* 024 */ s32 f24;
    /* 028 */ s64 f28;
    /* 030 */ s64 f30;
    /* 038 */ s32 f38[2];
    /* 040 */ s32 f40;
    /* 044 */ u16 f44;
    /* 046 */ char pad46[0x54 - 0x46];
    /* 054 */ u16 f54;
    /* 056 */ char pad56[0x58 - 0x56];
    /* 058 */ u8 f58;
    /* 059 */ u8 f59;
    /* 05A */ char pad5A[1];
    /* 05B */ u8 f5B;
    /* 05C */ u8 f5C;
    /* 05D */ u8 f5D;
    /* 05E */ char pad5E[0x64 - 0x5E];
    /* 064 */ s32 f64;
    /* 068 */ char pad68[0x6D - 0x68];
    /* 06D */ u8 f6D;
    /* 06E */ u8 f6E;
    /* 06F */ u8 f6F;
    /* 070 */ u8 f70;
    /* 071 */ u8 f71;
    /* 072 */ u8 f72;
    /* 073 */ u8 f73;
    /* 074 */ u8 f74;
    /* 075 */ char pad75[3];
    /* 078 */ char f78[0xC];

    s16 GetIdx();
} Dest;

inline s16 Dest::GetIdx() { return fC; }

extern s64 func_0035E320(void *arg0);
extern int func_00131188(char *buf, s32 value, s32 size);
extern s32 D_0042CDB4 __attribute__((section(".data")));

void func_00361660(s32 arg0, Dest *dst, s32 arg2, Src *src, u16 arg4) {
    s32 i;
    s32 idx;

    if (dst == 0) { return; }
    if (src == 0) { return; }
    dst->f00 = arg4;
    dst->f02 = src->f0C;
    dst->f04 = src->f00;
    dst->f08 = src;
    dst->fC = 0;
    dst->fE = 0;
    idx = dst->GetIdx();
    if (idx < 0 || idx >= 0x2BA) {
        idx = 0;
    }
    dst->f14 = D_0042CDB4 + idx * 0x50;
    dst->f1A = 0;
    dst->f18 = 0;
    dst->f19 = 0;
    dst->f1B = 0;
    dst->f1C = 0;
    dst->f20 = 0;
    dst->f22 = -1;
    dst->f24 = 0;
    dst->f28 = 0;
    dst->f30 = func_0035E320(src);
    for (i = 0; i < 2; i++) {
        dst->f38[i] = src->f160[i];
    }
    dst->f40 = src->fA6;
    dst->f44 = 0;
    dst->f54 = 0;
    dst->f58 = 0;
    dst->f59 = 0;
    dst->f5B = 0;
    dst->f5C = 0;
    dst->f5D = 0;
    dst->f64 = 0;
    dst->f6D = 0;
    dst->f6E = 0;
    dst->f6F = 0;
    dst->f70 = 0;
    dst->f71 = 0;
    dst->f72 = 0;
    dst->f73 = 0;
    dst->f74 = 0;
    func_00131188(dst->f78, 0, 0xC);
}

}  // extern "C"
