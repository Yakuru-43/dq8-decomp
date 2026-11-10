// range: 0x272900 0x272A60
// CLASS structural score=110 (98 words differ, 396 vs 348 bytes) -- best attempt
#include "common.h"

extern char D_003C9EF0[];
extern char D_003C9F50[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern u32 func_001341D8(char *);
extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, char *, char *, s8);
extern void func_00107040(void *, char *);
extern void func_001007A0(u32);
extern s32 func_002740D0(void *, void *, void *);
extern void *func_002745F0(void *, char *);

typedef union Word {
    f32 f;
    u32 u;
} Word;

typedef struct Node {
    u32 field_00;
    u32 field_04;
    u32 field_08;
    u32 field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
} Node;

typedef struct Tree {
    u32 field_00;
    Node *right;
} Tree;

typedef struct Lookup {
    /* 0x00 */ Node *node;
    /* 0x04 */ u8 flag04;
    /* 0x05 */ u8 pad05[7];
    /* 0x0C */ u8 byte0C;
    /* 0x10 */ Word word10;
    /* 0x14 */ Word word14;
} Lookup;

typedef struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ u32 ptr;
    /* 0x0C */ Word word0C;
} Str;

typedef struct Container {
    /* 0x00 */ u32 field_00[9];
    /* 0x24 */ Tree tree;
} Container;

typedef struct Rec {
    /* 0x00 */ u32 field_00;
    /* 0x04 */ Str str;
} Rec;

void func_00272900(u32 *out, Container *db, char *name, u32 *value)
{
    Lookup lk;
    Str str;
    u32 *word;
    u32 len;
    s32 i;
    Rec *rec;

    if (name == 0) {
        func_0012D4D8(D_003C9EF0, 286, D_003C9F50);
        *out = 0;
        return;
    }
    if (name[0] == 0) {
        func_0012D4D8(D_003C9EF0, 286, D_003C9F50);
        *out = 0;
        return;
    }
    lk.word14.u = 0;
    lk.word10.f = lk.word14.f;
    word = (u32 *)&str;
    for (i = 0; i < 3; i++) {
        word[i] = 0;
    }
    len = func_001341D8(name);
    func_001080E0(&str, len);
    func_00107100(&str, 0, 0, name, name + len, lk.byte0C);
    str.word0C = lk.word10;
    func_002740D0(&lk, &db->tree, &str);
    if ((str.flags & 1) != 0) {
        func_001007A0(str.ptr);
    }
    if (lk.flag04 == 0) {
        *out = 0;
        return;
    }
    rec = func_002745F0(db, (char *)lk.node + 0x18);
    func_00107040(&rec->str, name);
    rec->field_00 = *value;
    *out = lk.node->field_18;
}
