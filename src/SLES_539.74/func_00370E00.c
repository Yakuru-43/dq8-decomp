// range: 0x370E00 0x370F60
#include "common.h"

s32 func_00370F60(s32 arg0, s32 arg1);

typedef struct {
    /* 0x00 */ char pad_00[0xA];
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char pad_0C[0x4];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ char pad_14[0x2];
    /* 0x16 */ s16 unk_16;
} S_stats; /* size 0x18 */

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ S_stats stats;
} S_list; /* size 0x1C */

typedef struct {
    /* 0x00 */ char pad_00[0xC];
    /* 0x0C */ S_list *list;
} S_owner;

s32 func_00370E00(s32 arg0, s32 arg1, s32 arg2) {
    S_owner *owner = (S_owner *)arg0;
    S_list *list = owner->list;
    S_stats *stats;

    if (list == 0) {
        return 1;
    }
    if (list->unk_00 == 0) {
        return 1;
    }
    stats = &list->stats;
    if (func_00370F60(arg0, 1) != 0) {
        stats->unk_12 += (s16)arg1;
        if (stats->unk_0A < stats->unk_12) {
            stats->unk_16 = stats->unk_12 - stats->unk_0A;
            stats->unk_12 = stats->unk_0A;
        }
        return 1;
    }
    if (func_00370F60(arg0, 2) != 0) {
        stats->unk_12 = stats->unk_12 - (s16)arg1;
        if (stats->unk_12 < 0) {
            stats->unk_12 = 0;
        }
        if (stats->unk_12 < stats->unk_0A) {
            stats->unk_16 = 0;
        }
        return 1;
    }
    if (func_00370F60(arg0, 4) != 0) {
        stats->unk_10 += (s16)arg2;
        return 1;
    }
    if (func_00370F60(arg0, 8) == 0) {
        return 0;
    }
    stats->unk_10 = stats->unk_10 - (s16)arg2;
    return 1;
}
