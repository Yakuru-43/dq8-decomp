// range: 0x272C90 0x272DF0
#include "common.h"

extern char D_003C9EF0[];
extern char D_003C9F50[];

extern void func_0012D4D8(char *file, s32 line, char *expr);
extern u32 func_001341D8(char *);
extern void func_001080E0(void *, u32);
extern void func_00107100(void *, u32, u32, u32, u32, s8);
extern void func_001007A0(void *);
extern void func_00107040(void *, u32);
extern u32 *func_002744B0(void *, void *);
extern void func_00273E80(void **, s32, void *);

struct Str {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32 len;
    /* 0x08 */ char *ptr;
    /* 0x0C */ u32 field_0C;
    /* 0x18 */ void *field_18;
    /* 0x1C */ u8 field_1C;
    /* 0x24 */ s8 field_24;
    /* 0x28 */ f32 field_28;
    /* 0x2C */ s32 field_2C;
};

void func_00272C90(u32 *out, void *manager, char *name, u32 *src)
{
    struct Str s;
    u32 len;
    u32 *w;
    u32 i;
    u32 *node;

    if ((name == 0) || (name[0] == 0)) {
        func_0012D4D8(D_003C9EF0, 286, D_003C9F50);
        *out = 0;
        return;
    }
    s.field_2C = 0;
    s.field_28 = *(f32 *)&s.field_2C;
    i = 0;
    do {
        w = &s.flags + i;
        *w = 0;
    } while (++i < 3);
    len = func_001341D8(name);
    func_001080E0(&s, len);
    func_00107100(&s, 0, 0, (u32)name, (u32)name + len, s.field_24);
    s.field_0C = *(u32 *)&s.field_28;
    func_00273E80(&s.field_18, (s32)manager + 0x24, &s);
    if (s.flags & 1) {
        func_001007A0(s.ptr);
    }
    if (s.field_1C != 0) {
        node = func_002744B0(manager, (char *)s.field_18 + 0x18);
        func_00107040((char *)node + 4, (u32)name);
        *node = *src;
        *out = *(u32 *)((char *)s.field_18 + 0x18);
    } else {
        *out = 0;
    }
}
