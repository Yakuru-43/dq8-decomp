// range: 0x47B830 0x47B8F0
#include "common.h"

extern void func_1340C0(char *, char *);

extern char *D_003E1BD0 __attribute__((section(".sdata")));

typedef struct {
    s32 type;
    s32 unk4;
    char pad8[0x8];
    s32 sound;
    s32 sound2;
    char pad18[0x38];
    char *name;
    char *name54;
    char *name58;
} S_entry;

s32 func_0047B830(s32 arg0, s32 arg1, S_entry *arg2) {
    char *slot;
    s32 sound = arg2->sound;

    if (arg2->name != 0) {
        func_1340C0(D_003E1BD0 + sound * 64 + 0x2E64, arg2->name);
    }
    if (arg2->name54 != 0) {
        func_1340C0(D_003E1BD0 + sound * 64 + 0x2E84, arg2->name54);
    }
    if (arg2->name58 != 0) {
        func_1340C0(D_003E1BD0 + sound * 32 + 0x2FA4, arg2->name58);
    }
    slot = D_003E1BD0 + 0x3044;
    *(s32 *)(slot + sound * 4) = arg2->sound2;
    if (sound == 3) {
        *(u8 *)(D_003E1BD0 + 0x3080) = 1;
    }
    return 0;
}
