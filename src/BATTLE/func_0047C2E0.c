// range: 0x47C2E0 0x47C3E0
#include "common.h"

typedef struct Actor {
    char pad0[0xC];
    s16 unkC;
    char padE[0x56];
    s32 unk64;
    s32 unk68;
    char pad6C[0x31C];
    u8 unk388;
} Actor;

void func_360450();                                         /* extern */
M2C_UNK func_357490(M2C_UNK *, M2C_UNK *, M2C_UNK *);       /* extern */
s32 func_359A90(M2C_UNK *, s32, Actor **, s32, s32, s32, s32, s32, s32); /* extern */
s32 func_0047AF80(Actor *, s32 *);                          /* extern */
void func_16B5F0(char *, s32, s32);                        /* extern */
void func_16B6F0(char *, s32, s32);                        /* extern */

extern M2C_UNK D_421AD0 __attribute__((section(".data")));
extern M2C_UNK D_4218B0 __attribute__((section(".data")));
extern M2C_UNK D_4218F0 __attribute__((section(".data")));

s32 func_0047C2E0(char *arg0) {
    Actor *buf[0x20];
    s32 count;
    s32 i;

    func_360450();
    func_357490(&D_421AD0, &D_4218B0, &D_4218F0);
    count = func_359A90(&D_421AD0, 1, buf, 0x20, 1, 1, 0, -1, 1);
    for (i = 0; i < count; i++) {
        if (func_0047AF80(buf[i], NULL) > 0) {
            func_16B6F0(arg0, 1, buf[i]->unkC);
        } else {
            func_16B5F0(arg0, 1, buf[i]->unkC);
            buf[i]->unk388 = 0;
        }
    }
    return 0;
}
