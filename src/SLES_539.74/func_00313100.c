// range: 0x313100 0x313230
#include "common.h"

struct Unk68 {
    u8 pad0[0xC];
    s32 kind;
    s32 f10;
    s32 f14;
    u8 pad18[0x48];
    s32 f60;
    s32 f64;
    u8 f68;
};

struct Unk12 {
    u8 pad0[0x10];
    s16 h10;
    s16 h12;
};

struct Unk00 {
    struct Unk12 *next;
};

extern void func_00313230(struct Unk68 *);
extern s32 D_003E1180 __attribute__((section(".sdata")));
extern s32 D_00452BF0 __attribute__((section(".data")));
extern struct Unk00 *D_00452BE0 __attribute__((section(".data")));

s32 func_00313100(struct Unk68 *obj) {
    struct Unk12 *b;

    func_00313230(obj);
    if (obj->kind == 3 || obj->kind == 5) {
        obj->f10 = 2;
        obj->f14 = 0;
        obj->f60 = 0;
        obj->f64 = 1;
        obj->f68 = 0;
        return 1;
    }
    if (obj->kind == 2 || obj->kind == 4) {
        if (D_003E1180 == 1) {
            b = D_00452BE0->next;
            if (b != 0) {
                obj->f10 = b->h10;
                obj->f14 = 0;
                obj->f60 = 0;
                obj->f64 = 1;
                obj->f68 = 0;
            }
            return 1;
        }
    }
    if (obj->kind == 1) {
        if (D_003E1180 == 1) {
            if (D_00452BF0 == 1) {
                b = D_00452BE0->next;
                if (b != 0) {
                    obj->f10 = b->h10;
                    obj->f14 = D_00452BE0->next->h12;
                    obj->f60 = 0;
                    obj->f64 = 1;
                    obj->f68 = 0;
                }
                return 1;
            }
        }
    }
    return 0;
}
