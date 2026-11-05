// range: 0x372E60 0x372F10
#include "common.h"

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 (*fn0)(void *, s32);
} S_child;

typedef struct {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ S_child *unk_08;
    /* 0x0C */ s32 unk_0C;
} S_owner;

s32 *func_00372F10(char *, s32);

s32 func_00372E60(S_owner *s, s32 arg1, s32 arg2) {
    s32 value;

    if (s->unk_0C == 0) {
        return 0;
    }
    if (func_00372F10((char *)s, arg1) == 0) {
        return 0;
    }
    s->unk_08 = 0;
    s->unk_00 = arg1;
    value = arg1;
    if (arg2 != 0) {
        s->unk_08 = (S_child *)func_00372F10((char *)s, s->unk_00);
        if (s->unk_08 != 0) {
            s->unk_00 = 0;
            s->unk_08->fn0(&value, 1);
        }
    }
    return 1;
}
