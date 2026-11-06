// range: 0x180E00 0x180EA0
#include "common.h"

extern void func_00181030(void *);
extern void *func_00180FC0(void *);
extern void *func_00180FA0(void *);
extern s32 func_00180F90(void *);
extern s32 func_00180F60(char *);
extern void *func_00180F30(void *);
extern void *func_00180F00(void *);
extern void *func_00180ED0(void *);
extern void *func_00180EA0(void *);
extern M2C_UNK D_003DE8D0 __attribute__((section(".data")));
extern M2C_UNK D_003DE870 __attribute__((section(".data")));

struct Obj {
    u8 pad_000[0x1B0];
    void *vptr; /* +0x1B0 */
};

void *func_00180E00(struct Obj *arg0) {
    char *p;

    func_00181030(arg0);
    arg0->vptr = &D_003DE8D0;
    func_00180FC0((char *)arg0 + 0x4F0);
    func_00180FA0((char *)arg0 + 0x548);
    p = (char *)arg0 + 0x558;
    do {
        func_00180F90(p);
        p += 4;
    } while (p < (char *)arg0 + 0x568);
    func_00180F60((char *)arg0 + 0x568);
    func_00180F30((char *)arg0 + 0x570);
    func_00180F00((char *)arg0 + 0x578);
    func_00180ED0((char *)arg0 + 0x580);
    func_00180EA0((char *)arg0 + 0x588);
    arg0->vptr = &D_003DE870;
    return arg0;
}
