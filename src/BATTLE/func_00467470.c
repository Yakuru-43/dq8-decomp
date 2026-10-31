// range: 0x467470 0x467500
#include "common.h"

extern void *D_003E1BA4 __attribute__((section(".sdata")));
extern void *D_003E1BA8 __attribute__((section(".sdata")));

void func_1A45F0(void *);

typedef struct {
    s32 val_00;
    s32 val_04;
    s32 val_08;
    s32 val_0C;
} S_467470;

void func_00467470(void) {
    S_467470 *base;
    S_467470 *entry;
    s32 i;
    s32 j;

    i = 0;
    do {
        func_1A45F0((char *)D_003E1BA4 + i * 1520);
        i++;
    } while (i < 64);
    base = (S_467470 *)D_003E1BA8;
    j = 0;
    do {
        entry = base + j;
        j++;
        entry->val_00 = -1;
        entry->val_04 = -1;
        entry->val_08 = 1;
        entry->val_0C = 0;
    } while (j < 32);
}
