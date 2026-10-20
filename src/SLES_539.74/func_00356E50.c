// range: 0x356E50 0x356FB0
#include "common.h"

struct Block {
    char pad[0x20];
    s32 f20;
    char pad24[4];
    s32 f28;
    s32 f2C;
    s32 f30[6];
};

struct Table {
    struct Block *base;
    s32 *f4;
    s32 pad8;
    s32 *fC;
    s32 pad10;
    s32 *slots[6];
};

extern struct Table D_00453D10 __attribute__((section(".data")));
extern s32 D_003D39C8 __attribute__((section(".data")));
extern s32 D_003D39E0 __attribute__((section(".data")));

extern char *func_00161E80(s32 arg0, s32 *arg1, s32 *arg2);
extern struct Block *func_0014E130(s32 arg0, s32 arg1);
extern void func_00130FD0(struct Block *arg0, char *arg1, u32 arg2);
extern void func_00300CB0(s32 arg0, s32 *arg1, s32 arg2);

/* pulls the entry for arg0 into a block reserved from arg1, and points the
 * six slots at their record inside it */
s32 func_00356E50(s32 arg0, s32 arg1) {
    struct Block *block;
    s32 *slot;
    s32 done;
    char *data;
    s32 count;
    s32 index;
    s32 size;
    u32 bytes;
    s32 i;

    D_00453D10.base = 0;
    D_00453D10.f4 = 0;
    D_00453D10.fC = 0;
    if (arg0 == 0 || arg1 == 0) {
        return 0;
    }
    done = 0;
    data = func_00161E80(arg0, &D_003D39C8, &size);
    if (data != 0) {
        bytes = size;
        if ((bytes & 0xF) != 0) {
            count = (bytes >> 4) + 1;
        } else {
            count = bytes >> 4;
        }
        block = func_0014E130(arg1, count);
        D_00453D10.base = block;
        if (block == 0) {
            func_00300CB0(0, &D_003D39E0, 0xD);
            done = 0;
        } else {
            func_00130FD0(block, data, bytes);
            block = D_00453D10.base;
            D_00453D10.f4 = (s32 *)((char *)block + block->f20);
            D_00453D10.fC = (s32 *)((char *)block + block->f28);
            for (i = 0; i < 6; i = i + 1) {
                block = D_00453D10.base;
                index = block->f30[i];
                if (index != 0) {
                    slot = (s32 *)((char *)block + block->f2C + index * 32);
                } else {
                    slot = 0;
                }
                D_00453D10.slots[i] = slot;
            }
            done = 1;
        }
    }
    return done;
}
