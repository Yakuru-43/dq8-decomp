// range: 0x3112C0 0x311470
#include "common.h"

struct Owner {
    s32 mode; /* +0x00 */
};

struct Entry {
    char pad0[0x28];
    char *items; /* +0x28 */
    s32 count;   /* +0x2C */
};

extern char D_003D09A0 __attribute__((section(".data")));
extern char D_003D09D0 __attribute__((section(".data")));

extern s32 func_00181420();
extern s32 func_00203B10(s32, s32);
extern s32 func_00203940(s32, s32, s32);
extern void func_002BF750(void *, s32, s32, s32, s32);
extern void func_001340C0(void *, char *);
extern void func_001632D0(void *, void *, s32 *);
extern s32 func_0014E130(void *, s32);
extern void func_0014E030(void *);

s32 func_003112C0(struct Owner *o, struct Entry *e) {
    s32 out;
    char query[0x5C];
    char key[0x50];

    query[0] = 0;
    switch (o->mode) {
    case 1:
        if (func_00203B10(func_00181420(), o->mode) != 5) {
            return 0;
        }
        func_002BF750(query, o->mode, func_00203940(func_00181420(), o->mode, 0), 0, 1);
        func_001340C0(key, &D_003D09A0);
        break;
    case 2:
        if (func_00203B10(func_00181420(), o->mode) != 0xB) {
            return 0;
        }
        func_002BF750(query, o->mode, func_00203940(func_00181420(), o->mode, 0), 0, 1);
        func_001340C0(key, &D_003D09D0);
        break;
    default:
        return 0;
    }
    func_001632D0(query, e->items + (e->count << 4), &out);
    func_0014E130(e, (out >> 4) + 1);
    func_0014E030(e);
    func_001632D0(key, e->items + (e->count << 4), &out);
    func_0014E130(e, (out >> 4) + 1);
    func_0014E030(e);
    return 1;
}
