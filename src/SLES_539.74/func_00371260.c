// range: 0x371260 0x3713C0
#include "common.h"

s32 func_003715D0(void *);
s32 func_003715E0(void *);
M2C_UNK DebugPrintf(M2C_UNK *, ...);
extern M2C_UNK D_003D5050 __attribute__((section(".data")));
extern M2C_UNK D_003D5070 __attribute__((section(".data")));

typedef struct {
    /* 0x00 */ char pad_00[0x8];
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk_16;
} S_stats; /* size 0x18 */

typedef struct {
    /* 0x00 */ char pad_00[0x18];
    /* 0x18 */ S_stats *stats;
} S_owner;

s32 func_00371260(S_owner *owner, s32 mode) {
    s32 v_b;
    s32 v_c;
    s32 v_d;
    s32 flags;
    s32 v_a;

    if (owner->stats == 0) {
        return 0;
    }
    v_b = owner->stats->unk_08;
    v_a = 0;
    v_d = owner->stats->unk_0A;
    v_c = 0;
    if (mode != 0) {
        v_a = v_b;
        v_c = v_d;
        v_b = 0;
        v_d = 0;
    }
    DebugPrintf(&D_003D5050, v_a, v_b, v_c, v_d);
    flags = 0;
    if (func_003715E0(owner->stats) < 0) {
        flags |= 1;
        owner->stats->unk_14 = 0;
        owner->stats->unk_10 = v_a;
    }
    if (owner->stats->unk_08 < func_003715E0(owner->stats)) {
        flags |= 2;
        owner->stats->unk_14 = 0;
        owner->stats->unk_10 = v_b;
    }
    if (func_003715D0(owner->stats) < 0) {
        flags |= 4;
        owner->stats->unk_16 = 0;
        owner->stats->unk_12 = v_c;
    }
    if (owner->stats->unk_0A < func_003715D0(owner->stats)) {
        flags |= 8;
        owner->stats->unk_16 = 0;
        owner->stats->unk_12 = v_d;
    }
    DebugPrintf(&D_003D5070, flags);
    return 1;
}
