// best attempt (no range line on purpose: gen_configs must ignore this): CLASS
// structural score=79 (75 words differ, 364 vs 348 bytes), -O3 plain C
#include "common.h"

extern char D_003C9EF0[];
extern char D_003C9F50[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern u32 func_001341D8(char *s);
extern void func_001080E0(void *str, u32 n);
extern void func_00107100(void *, u32, u32, u32, u32, s8);
extern void func_001007A0(void *node);
extern void func_00107040(void *str, u32 count);
extern void func_00273C30(void *, void *, void *);
extern void *func_00274370(void *, u32);

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
};

typedef struct EntryList {
    u32 field_00;
    u32 count;
    u32 field_08[3];
    u32 *array;
    u32 field_18;
    u32 tailCount;
    u32 *tailArray;
} EntryList;

typedef union FloatWord {
    f32 f;
    u32 w;
} FloatWord;

struct Rec {
    /* 0x00 */ u32 words[3];
    /* 0x0C */ u32 word0C;
    /* 0x10 */ u32 pad_10[2];
    /* 0x18 */ u32 field_18;
    /* 0x1C */ u8 flag_1C;
    /* 0x1D */ u8 pad_1D[7];
    /* 0x24 */ s8 byte_24;
    /* 0x25 */ u8 pad_25[3];
    /* 0x28 */ FloatWord f28;
    /* 0x2C */ FloatWord f2C;
};

void func_002726D0(u32 *out, EntryList *list, char *s, u32 *src) {
    struct Rec rec;
    u32 len;
    u32 i;
    void *node;

    if (s == 0 || s[0] == 0) {
        func_0012D4D8(D_003C9EF0, 286, D_003C9F50);
        *out = 0;
        return;
    }
    rec.f2C.w = 0;
    rec.f28.f = rec.f2C.f;
    for (i = 0; i < 3; i++) {
        rec.words[i] = 0;
    }
    len = func_001341D8(s);
    func_001080E0(&rec, len);
    func_00107100(&rec, 0, 0, (u32)s, (u32)s + len, rec.byte_24);
    rec.word0C = rec.f28.w;
    func_00273C30(&rec.field_18, &list->tailCount, &rec);
    if ((rec.words[0] & 1) != 0) {
        func_001007A0((void *)rec.words[2]);
    }
    if (rec.flag_1C == 0) {
        *out = 0;
        return;
    }
    node = func_00274370(list, rec.field_18 + 0x18);
    func_00107040((char *)node + 4, (u32)s);
    *(u32 *)node = *src;
    *out = *(u32 *)(rec.field_18 + 0x18);
}
