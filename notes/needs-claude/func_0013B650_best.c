// range: 0x13B650 0x13B6B0
#include "common.h"

extern void *func_00109F98(s32 index);
extern void func_0010A2C8(void *obj, char *name, s32 size);
extern s32 func_0010A568(void *obj, s32 mode, s32 arg);
extern char D_0039C940[];

/* Tag the current manager object and (re-)register it under its name. */
void func_0013B650(void) {
    s32 size = 0x40;
    void *obj;
    u8 b;

    obj = func_00109F98(0);
    b = *(u8 *)obj;
    b = (b & ~0x40) | size;
    *(u8 *)obj = b;
    func_0010A2C8(obj, D_0039C940, size);
    func_0010A568(obj, 0, 0);
}
