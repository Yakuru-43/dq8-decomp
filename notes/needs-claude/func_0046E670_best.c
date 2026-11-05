// range: 0x46E670 0x46E760
#include "common.h"

typedef struct {
    u8 active;
    u8 pad_01[0x14F];
} BtlEntry;

typedef struct {
    u8 pad_00[0x2DEC];
    s32 count;
} BtlBlock;

extern void (*D_004831B0[])(M2C_UNK *) __attribute__((section(".data")));
extern M2C_UNK D_42D390 __attribute__((section(".data")));
extern s32 func_36E5C0(M2C_UNK *);
extern void func_36D670(M2C_UNK *, M2C_UNK);

void func_0046E670(char *arg0, M2C_UNK *arg1) {
    BtlEntry *entries;
    u8 idx;
    s32 i;

    i = 0;
    entries = (BtlEntry *)(arg0 + 0x10);
    do {
        idx = entries[i].active;
        if (idx != 0) {
            D_004831B0[idx](arg1);
        }
        i += 1;
    } while (i < 32);
    if (((BtlBlock *)arg0)->count > 0) {
        if (func_36E5C0(&D_42D390) == 0) {
            ((BtlBlock *)arg0)->count = ((BtlBlock *)arg0)->count - 1;
            func_36D670(&D_42D390, 1);
        }
    }
}
