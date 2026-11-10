// range: 0x295680 0x2957C0
#include "common.h"

struct Record {
    s32 word0;
    char pad4[0xC];
    s16 val10;
    s16 val12;
};

struct Sub {
    char pad0[0xF0];
    s32 f0F0;
    s32 f0F4;
};

struct Found {
    s32 word0;
    s32 rest[11];
};

struct Owner {
    char pad0[0x58C];
    struct Sub *sub;
};

extern void func_00292830(struct Owner *owner);
extern s32 func_002915F0(struct Owner *owner, s32 kind);
extern void func_002912C0(struct Owner *owner);
extern s32 func_0035E590(struct Sub *sub);
extern s32 func_00359620(void *name, s32 id, struct Record **buf, s32 max,
                         s32 a, s32 b, s32 c, s32 d, s32 e);
extern s64 func_0035DE00(struct Record *rec);
extern s32 func_0028F4F0(void *a0, void *a1, s32 a2);
extern M2C_UNK D_00421AD0 __attribute__((section(".data")));
extern M2C_UNK D_00420C30 __attribute__((section(".data")));

s32 func_00295680(struct Owner *owner) {
    s32 sel;
    struct Record *found;
    s32 id;
    s32 count;
    s32 i;
    struct Record *buf[32];
    struct Found rec;

    func_00292830(owner);
    count = func_002915F0(owner, 0);
    if (count <= 0) {
        return 0;
    }
    func_002912C0(owner);
    sel = -1;
    found = 0;
    id = func_0035E590(owner->sub);
    count = func_00359620(&D_00421AD0, id, buf, 0x20, 0, 1, 0, sel, 0);
    if (count <= 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        found = buf[i];
        if (found->val10 != owner->sub->f0F0) {
            continue;
        }
        if (found->val12 != owner->sub->f0F4) {
            continue;
        }
        sel = found->word0;
        break;
    }
    if (found == 0 || sel <= 0) {
        return 0;
    }
    if ((s64)(s8)func_0035DE00(found) != 5) {
        rec.word0 = sel;
        return func_0028F4F0(&D_00420C30, &rec, 1) == 1;
    }
    return 1;
}
