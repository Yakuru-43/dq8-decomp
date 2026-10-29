// best attempt for func_00275880 (NOT a match: CLASS structural score=102)
// range: 0x275880 0x275A30
// Create a 0x1C buffer object from a source Str: heap sources are zeroed,
// grown and spliced in; plain sources copy their three words as floats.
#include "common.h"

extern u32 func_00100970(u32);
extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);
extern void func_00275D90(void *, u32);
extern void func_0012EFC8(u32, char *);
extern void func_0012D4A8(void);

extern u32 D_003A0788;
extern char D_003C9FB0[];
extern char D_003CA010[];

typedef union Word {
    u32 word;
    f32 f;
} Word;

struct Str {
    /* 0x00 */ Word flags;
    /* 0x04 */ Word len;
    /* 0x08 */ Word ptr;
    /* 0x0C */ u32 field0C;
};

struct Obj {
    /* 0x00 */ u32 field00;
    /* 0x04 */ u32 field04;
    /* 0x08 */ u32 flags;
    /* 0x0C */ Word data[3];
    /* 0x18 */ u32 field18;
};

struct Owner {
    /* 0x00 */ u32 field00;
    /* 0x04 */ u32 field04;
    /* 0x0C */ struct Obj *field0C;
};

struct Obj *func_00275880(struct Owner *owner, u32 mask, s32 sel, s32 set,
                          struct Str *src)
{
    struct Obj *obj;
    Word *buf;
    u32 i;
    u8 flag[4];

    if (owner->field00 == 0xFFFFFFFF) {
        func_0012EFC8(*(u32 *)(D_003A0788 + 0xC), D_003C9FB0);
        func_0012D4A8();
    }
    obj = (struct Obj *)func_00100970(0x1C);
    if (obj == 0) {
        func_0012EFC8(*(u32 *)(D_003A0788 + 0xC), D_003CA010);
        func_0012D4A8();
    }
    buf = obj->data;
    if (buf != 0) {
        if ((src->flags.word & 1) != 0) {
            for (i = 0; i < 3; i++) {
                buf[i].word = 0;
            }
            func_001080E0(buf, src->len.word);
            func_00107100(buf, 0, 0, src->ptr.word,
                          src->ptr.word + src->len.word, flag[0]);
        } else {
            buf[0].f = src->flags.f;
            buf[1].f = src->len.f;
            buf[2].f = src->ptr.f;
        }
        obj->field18 = src->field0C;
    }
    obj->field04 = 0;
    obj->field00 = 0;
    obj->flags = mask | (obj->flags & 1);
    if (sel != 0) {
        *(struct Obj **)mask = obj;
    } else {
        *(struct Obj **)(mask + 4) = obj;
    }
    owner->field00 = owner->field00 + 1;
    func_00275D90(obj, owner->field04);
    if (set != 0) {
        owner->field0C = obj;
    }
    return obj;
}
