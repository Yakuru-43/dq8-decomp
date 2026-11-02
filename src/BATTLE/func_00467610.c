// range: 0x467610 0x467790
#include "common.h"

extern void *func_14EB30(s32 size, void *arg1);
extern void *func_14EA80(s32 size, void *arg1);
extern void func_14E030(void *);
extern void *func_1AD890(void *);
extern void *func_1A87F0(void *);
extern void func_1A8610(void *, void *, s32);
extern void *func_100630(void *, void *, s32, s32, s32);
extern void func_1A48A0(void *, void *, s32);

extern void *D_003E1B98 __attribute__((section(".sdata")));
extern void *D_003E1B9C __attribute__((section(".sdata")));
extern void *D_003E1BA0 __attribute__((section(".sdata")));
extern void *D_003E1BA4 __attribute__((section(".sdata")));
extern void *D_003E1BA8 __attribute__((section(".sdata")));
extern M2C_UNK D_1A49E0 __attribute__((section(".data")));

typedef struct {
    s32 val_00;
    s32 val_04;
    s32 val_08;
    s32 val_0C;
} S_467610;

void func_00467610(void *arg0) {
    void *pool;
    void *rec;
    S_467610 *entry;
    s32 off;
    s32 i;

    pool = func_14EB30(0x200, arg0);
    if (pool != 0) {
        pool = func_1AD890(pool);
    }
    D_003E1BA8 = pool;
    i = 0;
    do {
        entry = (S_467610 *)pool + i;
        i++;
        entry->val_00 = -1;
        entry->val_04 = -1;
        entry->val_08 = 1;
        entry->val_0C = 0;
    } while (i < 32);
    func_14E030(arg0);
    D_003E1B98 = func_14EA80(0x1800, arg0);
    func_14E030(arg0);
    rec = func_14EB30(0xB70, arg0);
    if (rec != 0) {
        rec = func_1A87F0(rec);
    }
    D_003E1B9C = rec;
    func_1A8610(rec, D_003E1B98, 0x40);
    *(void **)((char *)D_003E1B9C + 0x90) = D_003E1BA8;
    func_14E030(arg0);
    D_003E1BA0 = func_14EA80(0x500, arg0);
    func_14E030(arg0);
    pool = func_14EA80(0x17C10, arg0);
    D_003E1BA4 = func_100630(pool, &D_1A49E0, 0, 0x5F0, 0x40);
    i = 0;
    do {
        off = i * 1520;
        func_1A48A0((char *)D_003E1BA4 + off, D_003E1BA0, 0x10);
        i++;
        *(void **)((char *)D_003E1BA4 + off + 0x40) = D_003E1BA8;
        *(s32 *)((char *)D_003E1BA4 + off + 0x68) = -1;
    } while (i < 64);
}
