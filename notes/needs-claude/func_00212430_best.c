// range: 0x212430 0x212500
// BEST attempt: CLASS structural score=12 (12 words, 204 vs 204 B).
// Register map correct (cursor -> $s1, arg1 -> $s0); remaining diffs are
// the family cursor-fold + guard1 polarity + delay-slot scheduling.
#include "common.h"

typedef struct {
    s32 type;
    s32 val;
} Item;

extern char *D_003E0908;
extern char *D_003E0944;
extern f32 D_003DF4B8;

u32 func_00166760(Item *);
s32 func_00133F78(char *, u32);
void func_002127B0(char *, Item *);
f32 func_00166780();
f32 func_0013BCA0(f32);

s32 func_00212430(Item *arg0, s32 arg1) {
    Item *cursor;
    u32 handle;

    handle = func_00166760(arg0);
    if (handle == 0) {
        return 0;
    }
    cursor = arg0;
    cursor = cursor + 1;
    M2C_FIELD(D_003E0944, u8 *, 0x75) = 1;
    if (func_00133F78(D_003E0908 + 0x3F4, handle) != 0) {
        return 0;
    }
    func_002127B0(D_003E0908 + 0x430, cursor);
    if (arg1 >= 5) {
        M2C_FIELD(D_003E0944, f32 *, 0x78) = func_00166780((char *)cursor + 0x18);
        M2C_FIELD(D_003E0944, f32 *, 0x78) =
            func_0013BCA0(D_003DF4B8 * M2C_FIELD(D_003E0944, f32 *, 0x78));
    }
    M2C_FIELD(D_003E0944, u8 *, 0x74) = 1;
    M2C_FIELD(D_003E0944, u8 *, 0x75) = 2;
    return 1;
}
