// range: 0x372D60 0x372E00
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

s32 func_00372D60(S_owner *s) {
    s32 ret;

    if (s->unk_0C == 0) {
        return 1;
    }
    if (s->unk_08 != 0) {
        ret = s->unk_08->fn0((char *)s + 4, 0);
    } else {
        s->unk_08 = (S_child *)func_00372F10((char *)s, s->unk_00);
        if (s->unk_08 != 0) {
            s->unk_00 = 0;
            s->unk_04 = 0;
            ret = s->unk_08->fn0((char *)s + 4, 1);
        }
    }
    return ret;
}
